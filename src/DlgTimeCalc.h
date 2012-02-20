/**
Copyright (C) 2012 Ros Mc Mahon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
**/

#pragma once
#include <QDialog>
#include <QKeyEvent>
#include "../build/ui_TimeCalculatorGui.h"

#include <cstdlib>

class DlgTimeCalc :
	public QDialog,
	private Ui::dlgTimeCalculator
{
	Q_OBJECT

public:
	DlgTimeCalc(void);

private slots:
	void keyPressEvent( QKeyEvent * key );
	void on_btnPlus_clicked();
	void on_lineSecs_textEdited(const QString & text);
	void on_btnMinus_clicked();
	void on_btnClear_clicked();
	void on_btnAdd_clicked();


private:
	/* private members */
	int _ans, _tot; //for holding running sums (in secs)
	QPalette _palSecs; //used to store original colours of lineSecs
	/* private functions */
	void displayAns();
	void displayTot();
};
