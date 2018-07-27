/*
|| @file IC.RobotMotor.h
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

#ifndef IC_ROBOTMOTOR_H_
#define IC_ROBOTMOTOR_H_

#include <Arduino.h>
#define Forward     1
#define Left        2
#define Right       3
#define Backword    4
#define Left90      5
#define Right90     6
#define Stop        0

namespace IC
{
	class RobotMotor
	{
	private:
		uint8_t pwm;
		int lsed;
		int rsed;
		int* leftpins;
		int* rightpins;
		int* speeds;
		int f1(uint8_t seg, int v1, int v2);
	public:
		RobotMotor(int left1, int left2, int right1, int right2);
		RobotMotor(int leften, int left1, int left2, int righten, int right1, int right2);
		void begin();
		void Go(int how);
		void Go(int how, int speed);
		void forward();
		void left();
		void right();
		void backword();
		void left90();
		void right90();
		void stop();
		void SetSpeed(int speed);
		void SetSpeed(int side, int speed);
		void StraightTurn(int side, int chang);
		void StraightTurn(int side, int chang, int speed);
		void SpeedTurn(int side, int chang);
		void StopTurn(int side);
		int GetSpeed(int side);
	};
};
#endif
