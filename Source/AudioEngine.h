/****************************************************************************
 *  File name: AudioEngine.h
 *  Description:
 *      - The interface for the core audio systems in the engine.
  
 *  Based on a tutorial by Cody Claborn
*****************************************************************************/
#pragma once

#include "Vector3D.h"
#include "fmod.hpp"
#include "fmod_studio.hpp"

#include <string>
namespace Audio
{

  /* Constants                      */

  /* Enums                          */

  /* Public classes                 */

  /* Public functions declarations  */

  void Initialize();
  void Update();
  void Shutdown();
  
  int ErrorCheck(FMOD_RESULT result);
  void LoadBank(const std::string& name, FMOD_STUDIO_LOAD_BANK_FLAGS flags);
  void LoadEvent(const std::string& name);
  void LoadSound(const std::string& name, bool is3D = true, bool isLooping = false, bool isStream = false);
  void FreeSound(const std::string& strSoundName);
  void Set3dListenerAndOrientation(const Vector3D& pos = Vector3D{ 0,0,0 }, float volume = 0.0f);
  int PlaySound(const std::string& strSoundName, const Vector3D& vPos = Vector3D{ 0, 0, 0 }, float fVolumedB = 0.0f);
  void PlayEvent(const std::string& strEventName);
  void StopChannel(int nChannelId);
  void StopEvent(const std::string& strEventName, bool bImmediate = false);
  void GeteventParameter(const std::string& strEventName, const std::string& strEventParameter, float* parameter);
  void SetEventParameter(const std::string& strEventName, const std::string& strParameterName, float fValue);
  void StopAllChannels();
  void SetChannel3dPosition(int nChannelId, const Vector3D& vPosition);
  void SetChannelvolume(int nChannelId, float fVolumedB);
  bool IsPlaying(int nChannelId);
  bool IsEventPlaying(const std::string& strEventName);
  float dbToVolume(float db);
  float VolumeTodb(float volume);
  FMOD_VECTOR VectorToFmod(const Vector3D& vPosition);
}
