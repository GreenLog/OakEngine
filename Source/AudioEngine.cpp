/****************************************************************************
 *  File name: AudioEngine.cpp
 *  Description:
 *      - The core audio systems in the engine.

 *  Based on a tutorial by Cody Claborn
*****************************************************************************/
#include "OEngine.h"

#include "AudioEngine.h"
#include <map>
#include <vector>
#include <iostream>

using std::vector;
namespace Audio
{

  /* Constants                      */

  /* Enums                          */

  /* Private classes                */
  struct Implementation
  {
    Implementation()
      :mnNextChannelId(0)
    {
      mpStudioSystem = NULL;
      ErrorCheck(FMOD::Studio::System::create(&mpStudioSystem));
      ErrorCheck(mpStudioSystem->initialize(32, FMOD_STUDIO_INIT_LIVEUPDATE, FMOD_INIT_PROFILE_ENABLE, NULL));

      mpSystem = NULL;
      ErrorCheck(mpStudioSystem->getCoreSystem(&mpSystem));

    }
    ~Implementation()
    {
      ErrorCheck(mpStudioSystem->unloadAll());
      ErrorCheck(mpStudioSystem->release());
    }

    void Update()
    {
      vector<ChannelMap::iterator> pStoppedChannels;
      for (auto it = mChannels.begin(), itEnd = mChannels.end(); it != itEnd; ++it)
      {
        bool bIsPlaying = false;
        it->second->isPlaying(&bIsPlaying);
        if (!bIsPlaying)
        {
          pStoppedChannels.push_back(it);
        }
      }
      for (auto& it : pStoppedChannels)
      {
        mChannels.erase(it);
      }
      ErrorCheck(mpStudioSystem->update());
    }

    FMOD::Studio::System* mpStudioSystem;
    FMOD::System* mpSystem;

    int mnNextChannelId;

    typedef std::map<std::string, FMOD::Sound*> SoundMap;
    typedef std::map<int, FMOD::Channel*> ChannelMap;
    typedef std::map<std::string, FMOD::Studio::EventInstance*> EventMap;
    typedef std::map<std::string, FMOD::Studio::Bank*> BankMap;

    BankMap mBanks;
    EventMap mEvents;
    SoundMap mSounds;
    ChannelMap mChannels;
  };
  Implementation* sgpImplementation = nullptr;
  /* Public variables               */

  /* Private variables              */

  /* Private functions declarations */

  /* Public functions definitions   */

  void Initialize()
  {
    sgpImplementation = new Implementation;
  }

  void Update()
  {
    sgpImplementation->Update();
  }

  void Shutdown()
  {
    delete sgpImplementation;
  }

  int ErrorCheck(FMOD_RESULT result)
  {
    if (result != FMOD_OK) {
      std::cout << "FMOD ERROR " << result << std::endl;
      return 1;
    }
    // cout << "FMOD all good" << endl;
    return 0;
  }

  void LoadBank(const std::string& name, FMOD_STUDIO_LOAD_BANK_FLAGS flags)
  {
    auto tFoundIt = sgpImplementation->mBanks.find(name);
    if (tFoundIt != sgpImplementation->mBanks.end())
      return;
    FMOD::Studio::Bank* pBank;
    ErrorCheck(sgpImplementation->mpStudioSystem->loadBankFile(name.c_str(), flags, &pBank));
    if (pBank) {
      sgpImplementation->mBanks[name] = pBank;
    }
  }

  void LoadEvent(const std::string& name)
  {
    auto tFoundit = sgpImplementation->mEvents.find(name);
    if (tFoundit != sgpImplementation->mEvents.end())
      return;
    FMOD::Studio::EventDescription* pEventDescription = NULL;
    ErrorCheck(sgpImplementation->mpStudioSystem->getEvent(name.c_str(), &pEventDescription));
    if (pEventDescription) {
      FMOD::Studio::EventInstance* pEventInstance = NULL;
      ErrorCheck(pEventDescription->createInstance(&pEventInstance));
      if (pEventInstance) {
        sgpImplementation->mEvents[name] = pEventInstance;
      }
    }
  }

  void LoadSound(const std::string& name, bool is3D, bool isLooping, bool isStream)
  {
    auto tFoundIt = sgpImplementation->mSounds.find(name);
    if (tFoundIt != sgpImplementation->mSounds.end())
      return;

    FMOD_MODE eMode = FMOD_DEFAULT;
    eMode |= is3D ? FMOD_3D : FMOD_2D;
    eMode |= isLooping ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
    eMode |= isStream ? FMOD_CREATESTREAM : FMOD_CREATECOMPRESSEDSAMPLE;

    FMOD::Sound* pSound = nullptr;
    ErrorCheck(sgpImplementation->mpSystem->createSound(name.c_str(), eMode, nullptr, &pSound));
    if (pSound) {
      sgpImplementation->mSounds[name] = pSound;
    }
  }

  void FreeSound(const std::string& strSoundName)
  {
    auto tFoundIt = sgpImplementation->mSounds.find(strSoundName);
    if (tFoundIt == sgpImplementation->mSounds.end())
      return;

    ErrorCheck(tFoundIt->second->release());
    sgpImplementation->mSounds.erase(tFoundIt);
  }

  void Set3dListenerAndOrientation(const Vector3D& pos, float volume)
  {

  }

  int PlaySound(const std::string& strSoundName, const Vector3D& vPos, float fVolumedB)
  {

    int nChannelId = sgpImplementation->mnNextChannelId++;
    auto tFoundIt = sgpImplementation->mSounds.find(strSoundName);
    if (tFoundIt == sgpImplementation->mSounds.end())
    {
      LoadSound(strSoundName);
      tFoundIt = sgpImplementation->mSounds.find(strSoundName);
      if (tFoundIt == sgpImplementation->mSounds.end())
      {
        return nChannelId;
      }
    }
    FMOD::Channel* pChannel = nullptr;
    ErrorCheck(sgpImplementation->mpSystem->playSound(tFoundIt->second, nullptr, true, &pChannel));
    if (pChannel)
    {
      FMOD_MODE currMode;
      tFoundIt->second->getMode(&currMode);
      if (currMode & FMOD_3D) {
        FMOD_VECTOR position = VectorToFmod(vPos);
        ErrorCheck(pChannel->set3DAttributes(&position, nullptr));
      }
      ErrorCheck(pChannel->setVolume(dbToVolume(fVolumedB)));
      ErrorCheck(pChannel->setPaused(false));
      sgpImplementation->mChannels[nChannelId] = pChannel;
    }
    return nChannelId;
  }

  void PlayEvent(const std::string& strEventName)
  {
    auto tFoundit = sgpImplementation->mEvents.find(strEventName);
    if (tFoundit == sgpImplementation->mEvents.end()) {
      LoadEvent(strEventName);
      tFoundit = sgpImplementation->mEvents.find(strEventName);
      if (tFoundit == sgpImplementation->mEvents.end())
        return;
    }
    tFoundit->second->start();
  }

  void StopChannel(int nChannelId)
  {
  }

  void StopEvent(const std::string& strEventName, bool bImmediate)
  {
    auto tFoundIt = sgpImplementation->mEvents.find(strEventName);
    if (tFoundIt == sgpImplementation->mEvents.end())
      return;

    FMOD_STUDIO_STOP_MODE eMode;
    eMode = bImmediate ? FMOD_STUDIO_STOP_IMMEDIATE : FMOD_STUDIO_STOP_ALLOWFADEOUT;
    ErrorCheck(tFoundIt->second->stop(eMode));
  }

  void GeteventParameter(const std::string& strEventName, const std::string& strEventParameter, float* parameter)
  {
    auto tFoundIt = sgpImplementation->mEvents.find(strEventName);
    if (tFoundIt == sgpImplementation->mEvents.end())
      return;

    ErrorCheck(tFoundIt->second->getParameterByName(strEventParameter.c_str(), parameter));
  }

  void SetEventParameter(const std::string& strEventName, const std::string& strParameterName, float fValue)
  {
    auto tFoundIt = sgpImplementation->mEvents.find(strEventName);
    if (tFoundIt == sgpImplementation->mEvents.end())
      return;

    ErrorCheck(tFoundIt->second->setParameterByName(strParameterName.c_str(), fValue));
  }

  void StopAllChannels()
  {
  }

  void SetChannel3dPosition(int nChannelId, const Vector3D& vPosition)
  {
    auto tFoundIt = sgpImplementation->mChannels.find(nChannelId);
    if (tFoundIt == sgpImplementation->mChannels.end())
      return;

    FMOD_VECTOR position = VectorToFmod(vPosition);
    ErrorCheck(tFoundIt->second->set3DAttributes(&position, NULL));
  }

  void SetChannelvolume(int nChannelId, float fVolumedB)
  {
    auto tFoundIt = sgpImplementation->mChannels.find(nChannelId);
    if (tFoundIt == sgpImplementation->mChannels.end())
      return;

    ErrorCheck(tFoundIt->second->setVolume(dbToVolume(fVolumedB)));
  }

  bool IsPlaying(int nChannelId)
  {
    return false;
  }

  bool IsEventPlaying(const std::string& strEventName)
  {
    auto tFoundIt = sgpImplementation->mEvents.find(strEventName);
    if (tFoundIt == sgpImplementation->mEvents.end())
      return false;

    FMOD_STUDIO_PLAYBACK_STATE* state = NULL;
    if (tFoundIt->second->getPlaybackState(state) == FMOD_STUDIO_PLAYBACK_PLAYING) {
      return true;
    }
    return false;
  }

  float dbToVolume(float db)
  {
    return powf(10.0f, 0.05f * db); return 0.0f;
  }

  float VolumeTodb(float volume)
  {
    return 20.0f * log10f(volume);
  }

  FMOD_VECTOR VectorToFmod(const Vector3D& vPosition)
  {
    FMOD_VECTOR fVec;
    fVec.x = vPosition.x;
    fVec.y = vPosition.y;
    fVec.z = vPosition.z;
    return fVec;
  }

  /* Private functions definitions  */
}
