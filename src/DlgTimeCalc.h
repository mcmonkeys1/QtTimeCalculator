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
