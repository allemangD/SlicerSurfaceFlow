/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// .NAME vtkSlicerLibSurfaceFlowLogic - slicer logic class for volumes manipulation
// .SECTION Description
// This class manages the logic associated with reading, saving,
// and changing propertied of the volumes


#ifndef __vtkSlicerLibSurfaceFlowLogic_h
#define __vtkSlicerLibSurfaceFlowLogic_h

// Slicer includes
#include "vtkSlicerModuleLogic.h"

// MRML includes

// STD includes
#include <cstdlib>

#include "vtkSlicerLibSurfaceFlowModuleLogicExport.h"


class VTK_SLICER_LIBSURFACEFLOW_MODULE_LOGIC_EXPORT vtkSlicerLibSurfaceFlowLogic :
  public vtkSlicerModuleLogic
{
public:

  static vtkSlicerLibSurfaceFlowLogic *New();
  vtkTypeMacro(vtkSlicerLibSurfaceFlowLogic, vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent) override;

protected:
  vtkSlicerLibSurfaceFlowLogic();
  ~vtkSlicerLibSurfaceFlowLogic() override;

  void SetMRMLSceneInternal(vtkMRMLScene* newScene) override;
  /// Register MRML Node classes to Scene. Gets called automatically when the MRMLScene is attached to this logic class.
  void RegisterNodes() override;
  void UpdateFromMRMLScene() override;
  void OnMRMLSceneNodeAdded(vtkMRMLNode* node) override;
  void OnMRMLSceneNodeRemoved(vtkMRMLNode* node) override;
private:

  vtkSlicerLibSurfaceFlowLogic(const vtkSlicerLibSurfaceFlowLogic&); // Not implemented
  void operator=(const vtkSlicerLibSurfaceFlowLogic&); // Not implemented
};

#endif
