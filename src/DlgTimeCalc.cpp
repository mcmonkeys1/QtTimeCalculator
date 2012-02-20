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


#include "DlgTimeCalc.h"

DlgTimeCalc::DlgTimeCalc(void)
{
	setupUi(this);
	lineSecs->setValidator( new QIntValidator(this) ); //this makes it digits only
	
	_palSecs = lineSecs->palette(); //store original colours
	_ans = _tot = 0; //initialize sums
}

/* This is our main gui event switch */
void DlgTimeCalc::keyPressEvent( QKeyEvent * event )
{
	/* complete control over all keypreses */
	switch( event->key() )
	{
		case Qt::Key_Backspace: //clear current entry
			lineSecs->setText("00");
			lineMins->setText("0");
			lineSecs->setPalette( _palSecs );
			break;
		case Qt::Key_Delete:
			lineAnsSecs->setText("00");
			lineAnsMins->setText("0");
			_ans = 0;
			break;
		case Qt::Key_Plus:	//add entry to current total
			on_btnPlus_clicked();
			break;
		case Qt::Key_Minus:
			on_btnMinus_clicked();
			break;
		case Qt::Key_0:
		case Qt::Key_1:
		case Qt::Key_2:
		case Qt::Key_3:
		case Qt::Key_4:
		case Qt::Key_5:
		case Qt::Key_6:
		case Qt::Key_7:
		case Qt::Key_8:
		case Qt::Key_9:
			on_lineSecs_textEdited( lineSecs->text() + event->text() );
			break;
		default:
			lblMsg->setText(event->text());
			break;
	}

}

void DlgTimeCalc::displayAns()
{
	/* display current _ans in mins and secs */

	QString sMins, sSecs;
	int absAns = abs(_ans); //necessary for negative values
	//calc and set mins
	sMins = sMins.setNum( (absAns/60), 10);
	lineAnsMins->setText( sMins );
	int secs = absAns%60;
	sSecs = sSecs.setNum( secs, 10);
	if( secs <= 9 )
		lineAnsSecs->setText( "0" + sSecs );
	else 
		lineAnsSecs->setText( sSecs );

	//add '-' prefix if negative value
	if(_ans < 0)
		lineAnsMins->setText( "-" + lineAnsMins->text() );

}
void DlgTimeCalc::displayTot()
{
	/* display _tot in mins and secs */

	QString sMins, sSecs;
	int absTot = abs(_tot); //necessary for negative values
	//calc and set mins
	sMins = sMins.setNum( (absTot/60), 10);
	lineTotMins->setText( sMins );
	int secs = absTot%60;
	sSecs = sSecs.setNum( secs, 10);
	if( secs <= 9 )
		lineTotSecs->setText( "0" + sSecs );
	else 
		lineTotSecs->setText( sSecs );

	//add '-' prefix if negative value
	if(_ans < 0)
		lineTotMins->setText( "-" + lineTotMins->text() );	

}

void DlgTimeCalc::on_btnPlus_clicked()
{
	//get the mins and secs
	bool ok;
	int secs = lineSecs->text().toInt(&ok, 10);
	int mins = lineMins->text().toInt(&ok, 10);

	_ans = _ans + secs + (mins*60);

	displayAns();

	lineSecs->setText("00");
	lineMins->setText("0");

}

void DlgTimeCalc::on_btnMinus_clicked()
{
	//get the mins and secs
	bool ok;
	int secs = lineSecs->text().toInt(&ok, 10);
	int mins = lineMins->text().toInt(&ok, 10);

	_ans = _ans - secs - (mins*60);

	displayAns();

	lineSecs->setText("00");
	lineMins->setText("0");
}

/* Main functionality is to shift digits left into minutes box */
void DlgTimeCalc::on_lineSecs_textEdited(const QString & text)
{
	//shift digits into mins box
	if( ! lineMins->text().compare("0") ) //mins box starts with zeros in it
		lineMins->setText( text[0] );
	else
		lineMins->setText( lineMins->text() + text[0] );
	//get rid of shifted char
	QString s( text );
	s.remove(0,1); //remove first char
	lineSecs->setText( s );

	/* sanity checking (60 secs in a minute) */

	//convert text to int
	bool ok;
	int val = lineSecs->text().toInt(&ok, 10);
	//if more than 59 secs do something
	//we'll just highlight background in red as could be shifted in next iteration
	if(val < 60)
	{
		lineSecs->setPalette( _palSecs );
	}
	else //if(val > 59)
	{
		//change bg colour to red
		QPalette pal = lineSecs->palette();
		pal.setColor( QPalette::Base, QColor(255,0,0) );
		lineSecs->setPalette( pal );
	}

}

void DlgTimeCalc::on_btnClear_clicked()
{
	_tot = 0;
	displayTot();
}
void DlgTimeCalc::on_btnAdd_clicked()
{
	_tot += _ans;
	_ans = 0;
	displayTot();
	displayAns();
}