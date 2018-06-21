/*
|| @file example.ino
|| @version 1.0
|| @author Imesh Chamara
|| @contact imesh1chamara@gmail.com
||
|| @description
|| | Example for the IC.RobotMotor
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
#include <IC.RobotMotor.h>
using namespace IC;
RobotMotor Motors(7, 6, 5, 4, 3, 2);
void setup()
{
  Serial.begin(115200);
  Motors.begin();
  Motors.SetSpeed(50);
}
void loop(){
  Motors.Go(Forward);
  delay(1000);
  Motors.Go(Left);
  delay(1000);
  Motors.Go(Right);
  delay(1000);
  Motors.Go(Backword);
  delay(1000);
  Motors.Go(Stop);
  delay(1000);
}
