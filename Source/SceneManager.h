/****************************************************************************
 *  File name: SceneManager.h
 *  Description:
 *      - 
  
*****************************************************************************/
#pragma once

typedef class Scene Scene;

/* Constants                      */

/* Enums                          */

/* Public classes                 */

/* Public functions declarations  */

void SceneManagerSetFirstScene(Scene& scene);

void SceneManagerSetNextScene(Scene& scene, bool forced = false);

void SceneManagerPlayCurrentScene();

void SceneManagerAddScene(Scene& scene);

void SceneManagerPopScene();

void SceneManagerPopSceneFront();

void SceneManagerRemoveScene(Scene& scene);

void SceneManagerRemoveScene(int position);

void SceneManagerInsertScene(Scene& scene, int position);

void SceneManagerAdvanceScene();

