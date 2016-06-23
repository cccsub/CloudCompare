﻿//#######################################################################################
//#                                                                                     #
//#                              CLOUDCOMPARE PLUGIN: qCSF                              #
//#                                                                                     #
//#  Please cite the following paper, If you use this plugin in your work.              #
//#                                                                                     #
//#  Zhang W, Qi J, Wan P, Wang H, Xie D, Wang X, Yan G. An Easy-to-Use Airborne LiDAR  #
//#  Data Filtering Method Based on Cloth Simulation. Remote Sensing. 2016; 8(6):501.   #
//#                                                                                     #
//#                                     Copyright ©                                     #
//#               RAMM laboratory, School of Geography, Beijing Normal University       #
//#                               (http://ramm.bnu.edu.cn/)                             #
//#                                                                                     #
//#                      Wuming Zhang; Jianbo Qi; Peng Wan; Hongtao Wang                #
//#                                                                                     #
//#                      contact us: 2009zwm@gmail.com; wpqjbzwm@126.com                #
//#                                                                                     #
//#######################################################################################

#include "ccCSFDlg.h"

#include <ccOctree.h>

static int MaxIteration = 500;
static double cloth_resolution = 1.5;
static double class_threshold = 0.5;
ccCSFDlg::ccCSFDlg(QWidget* parent) : QDialog(parent), Ui::CSFDialog()
{
	setupUi(this);

	connect(buttonBox, SIGNAL(accepted()), this, SLOT(saveSettings()));

	setWindowFlags(Qt::Tool/*Qt::Dialog | Qt::WindowStaysOnTopHint*/);

	MaxIterationSpinBox->setValue(MaxIteration);
	cloth_resolutionSpinBox->setValue(cloth_resolution);
	class_thresholdSpinBox->setValue(class_threshold);

}

void ccCSFDlg::saveSettings()
{
   	MaxIteration=MaxIterationSpinBox->value();
   	cloth_resolution=cloth_resolutionSpinBox->value();
    class_threshold=class_thresholdSpinBox->value();
}