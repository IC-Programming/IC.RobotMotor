/*
|| @file IC.RobotMotor.cpp
|| @version 1.0
|| @author Imesh Chamara
|| @contact imesh1chamara@gmail.com, +94717401880
||
|| @description
|| | IC.RobotMotor library
|| #
||
|| @license
|| | This library is free software; you can redistribute it and/or
|| | modify it under the terms of the GNU Lesser General Public
|| | License as published by the Free Software Foundation; version
|| | 2.1 of the License.
|| |
|| | This library is distributed in the hope that it will be useful,
|| | but WITHOUT ANY WARRANTY; without even the implied warranty of
|| | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
|| | Lesser General Public License for more details.
|| |
|| | You should have received a copy of the GNU Lesser General Public
|| | License along with this library; if not, write to the Free Software
|| | Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
|| #
||
*/
#include<IC.RobotMotor.h>
namespace IC
{
	RobotMotor::RobotMotor(int left1, int left2, int right1, int right2)
	{
		pwm = 1;
		leftpins = new int[2];
		leftpins[0] = left1;
		leftpins[1] = left2;
		rightpins = new int[2];
		rightpins[0] = right1;
		rightpins[1] = right2;
		speeds = new int[2];
		speeds[0] = 0;
		speeds[1] = 0;
	}
	RobotMotor::RobotMotor(int leften, int left1, int left2, int righten, int right1, int right2)
	{
		pwm = 2;
		leftpins = new int[3];
		leftpins[0] = left1;
		leftpins[1] = left2;
		leftpins[2] = leften;
		rightpins = new int[3];
		rightpins[0] = right1;
		rightpins[1] = right2;
		rightpins[2] = righten;
		speeds = new int[2];
		stop();
		SetSpeed(255);
	}
	void RobotMotor::begin()
	{
		for (int i = 0; i < 2; i++)
		{
			pinMode(leftpins[i], OUTPUT);
		}
		for (int i = 0; i < 2; i++)
		{
			pinMode(rightpins[i], OUTPUT);
		}
		if (pwm == 2)
		{
			pinMode(leftpins[2], OUTPUT);
			pinMode(rightpins[2], OUTPUT);
		}
	}
	void RobotMotor::Go(int how)
	{
		if (pwm == 2)
		{
			analogWrite(leftpins[2], speeds[0]);
			analogWrite(rightpins[2], speeds[1]);
		}
		if (how == Stop)
			stop();
		else if (how == Forward)
			forward();
		else if (how == Left)
			left();
		else if (how == Right)
			right();
		else if (how == Backword)
			backword();
		else if (how == Left90)
			left90();
		else if (how == Right90)
			right90();
	}
	void RobotMotor::Go(int how, int speed)
	{
		if (pwm == 2)
		{
			analogWrite(leftpins[2], speed);
			analogWrite(rightpins[2], speed);
			pwm = 1;
			Go(how);
			pwm = 2;
		}
		else
			Go(how);
	}
	void RobotMotor::forward()
	{
		digitalWrite(leftpins[1], 0);
		digitalWrite(leftpins[0], 1);
		digitalWrite(rightpins[1], 0);
		digitalWrite(rightpins[0], 1);
	}
	void RobotMotor::left()
	{
		digitalWrite(leftpins[0], 0);
		digitalWrite(leftpins[1], 0);
		digitalWrite(rightpins[1], 0);
		digitalWrite(rightpins[0], 1);
	}
	void RobotMotor::right()
	{
		digitalWrite(leftpins[1], 0);
		digitalWrite(leftpins[0], 1);
		digitalWrite(rightpins[0], 0);
		digitalWrite(rightpins[1], 0);
	}
	void RobotMotor::backword()
	{
		digitalWrite(leftpins[0], 0);
		digitalWrite(leftpins[1], 1);
		digitalWrite(rightpins[0], 0);
		digitalWrite(rightpins[1], 1);
	}
	void RobotMotor::left90()
	{
		digitalWrite(leftpins[0], 0);
		digitalWrite(leftpins[1], 1);
		digitalWrite(rightpins[1], 0);
		digitalWrite(rightpins[0], 1);
	}
	void RobotMotor::right90()
	{
		digitalWrite(leftpins[1], 0);
		digitalWrite(leftpins[0], 1);
		digitalWrite(rightpins[0], 0);
		digitalWrite(rightpins[1], 1);
	}
	void RobotMotor::stop()
	{
		digitalWrite(leftpins[0], 0);
		digitalWrite(leftpins[1], 0);
		digitalWrite(rightpins[0], 0);
		digitalWrite(rightpins[1], 0);
	}
	void RobotMotor::SetSpeed(int speed)
	{
		if (pwm == 2)
		{
			speeds[0] = speed;
			speeds[1] = speed;
			analogWrite(leftpins[2], speeds[0]);
			analogWrite(rightpins[2], speeds[1]);
		}
	}
	void RobotMotor::SetSpeed(int side, int speed)
	{
		if (pwm == 2)
		{
			if (side == Left)
			{
				speeds[0] = speed;
			}
			else if (side == Right)
			{
				speeds[1] = speed;
			}
			analogWrite(leftpins[2], speeds[0]);
			analogWrite(rightpins[2], speeds[1]);
		}
	}
	void RobotMotor::StraightTurn(int side, int chang)
	{
		if (pwm == 2)
			if (side == Left)
			{
				analogWrite(leftpins[2], f1(speeds[0] - chang <= 0, 0, speeds[0] - chang));
				analogWrite(rightpins[2], speeds[1]);
				forward();
			}
			else if (side == Right)
			{
				analogWrite(leftpins[2], speeds[0]);
				analogWrite(rightpins[2], f1(speeds[1] - chang <= 0, 0, speeds[1] - chang));
				forward();
			}
	}
	int RobotMotor::f1(uint8_t seg, int v1, int v2)
	{
		if (seg != 0)
			return v1;
		else
			return v2;
	}
	void RobotMotor::SpeedTurn(int side, int chang)
	{
		if (pwm == 2)
			if (side == Left)
			{
				analogWrite(leftpins[2], f1(speeds[0] - chang <= 0, 0, speeds[0] - chang));
				analogWrite(rightpins[2], f1(speeds[1] + chang >= 255, 255, speeds[1] + chang));
				forward();
			}
			else if (side == Right)
			{
				analogWrite(leftpins[2], f1(speeds[0] + chang >= 255, 255, speeds[0] + chang));
				analogWrite(rightpins[2], f1(speeds[1] - chang <= 0, 0, speeds[1] - chang));
				forward();
			}
	}
	void RobotMotor::StraightTurn(int side, int chang, int speed)
	{
		if (pwm == 2)
			if (side == Left)
			{
				analogWrite(leftpins[2], f1(speed - chang <= 0, 0, speed - chang));
				analogWrite(rightpins[2], speed);
				forward();
			}
			else if (side == Right)
			{
				analogWrite(leftpins[2], speed);
				analogWrite(rightpins[2], f1(speed - chang <= 0, 0, speed - chang));
				forward();
			}
	}
	void RobotMotor::StopTurn(int side)
	{
		if (side == Left)
			left();
		else if (side == Right)
			right();
	}
	int RobotMotor::GetSpeed(int side)
	{
		if (side == Left)
			return speeds[0];
		else if (side == Right)
			return speeds[1];
		return -1;
	}
}
 
