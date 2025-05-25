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

#ifndef __qSlicerLibSurfaceFlowFooBarWidget_h
#define __qSlicerLibSurfaceFlowFooBarWidget_h

// Qt includes
#include <QWidget>

// FooBar Widgets includes
#include "qSlicerLibSurfaceFlowModuleWidgetsExport.h"

class qSlicerLibSurfaceFlowFooBarWidgetPrivate;

class Q_SLICER_MODULE_LIBSURFACEFLOW_WIDGETS_EXPORT qSlicerLibSurfaceFlowFooBarWidget
  : public QWidget
{
  Q_OBJECT
public:
  typedef QWidget Superclass;
  qSlicerLibSurfaceFlowFooBarWidget(QWidget *parent=0);
  ~qSlicerLibSurfaceFlowFooBarWidget() override;

protected slots:

protected:
  QScopedPointer<qSlicerLibSurfaceFlowFooBarWidgetPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(qSlicerLibSurfaceFlowFooBarWidget);
  Q_DISABLE_COPY(qSlicerLibSurfaceFlowFooBarWidget);
};

#endif
