/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// FooBar Widgets includes
#include "qSlicerLibSurfaceFlowFooBarWidget.h"
#include "ui_qSlicerLibSurfaceFlowFooBarWidget.h"

//-----------------------------------------------------------------------------
class qSlicerLibSurfaceFlowFooBarWidgetPrivate
  : public Ui_qSlicerLibSurfaceFlowFooBarWidget
{
  Q_DECLARE_PUBLIC(qSlicerLibSurfaceFlowFooBarWidget);
protected:
  qSlicerLibSurfaceFlowFooBarWidget* const q_ptr;

public:
  qSlicerLibSurfaceFlowFooBarWidgetPrivate(
    qSlicerLibSurfaceFlowFooBarWidget& object);
  virtual void setupUi(qSlicerLibSurfaceFlowFooBarWidget*);
};

// --------------------------------------------------------------------------
qSlicerLibSurfaceFlowFooBarWidgetPrivate
::qSlicerLibSurfaceFlowFooBarWidgetPrivate(
  qSlicerLibSurfaceFlowFooBarWidget& object)
  : q_ptr(&object)
{
}

// --------------------------------------------------------------------------
void qSlicerLibSurfaceFlowFooBarWidgetPrivate
::setupUi(qSlicerLibSurfaceFlowFooBarWidget* widget)
{
  this->Ui_qSlicerLibSurfaceFlowFooBarWidget::setupUi(widget);
}

//-----------------------------------------------------------------------------
// qSlicerLibSurfaceFlowFooBarWidget methods

//-----------------------------------------------------------------------------
qSlicerLibSurfaceFlowFooBarWidget
::qSlicerLibSurfaceFlowFooBarWidget(QWidget* parentWidget)
  : Superclass( parentWidget )
  , d_ptr( new qSlicerLibSurfaceFlowFooBarWidgetPrivate(*this) )
{
  Q_D(qSlicerLibSurfaceFlowFooBarWidget);
  d->setupUi(this);
}

//-----------------------------------------------------------------------------
qSlicerLibSurfaceFlowFooBarWidget
::~qSlicerLibSurfaceFlowFooBarWidget()
{
}
