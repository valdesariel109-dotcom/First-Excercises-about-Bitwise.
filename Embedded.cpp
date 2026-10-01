#include <iostream>
#include<cstdint>
#include<bitset>

using Register8 = std::uint8_t;

constexpr uint8_t MOTOR_ENABLE_BIT = 0;

constexpr uint8_t SENSOR_FTL_BIT = 2;

constexpr uint8_t STATUS_LED_BIT = 5;

void printRegister(const char* label, Register8 reg){
	std::cout <<label <<"\n" << " Binary:" << std::bitset<8>(reg) << "\n" << " Hex  :0x" << std::hex << static_cast<int>(reg) <<std::dec <<"\n\n";
}

int main(){
	Register8 gpio_control_reg = 0x00;
	printRegister("Initial State:", gpio_control_reg);
	
	gpio_control_reg|=(1U << MOTOR_ENABLE_BIT);
	printRegister("After SET Motor Enable (Bit 0):", gpio_control_reg);
	
	gpio_control_reg|=(1U << STATUS_LED_BIT);
	printRegister("After SET Status LED (Bit 5):", gpio_control_reg);
	
	gpio_control_reg^=(1U << STATUS_LED_BIT);
	printRegister("After TOGGLE Status LED (Bit 5):", gpio_control_reg);
	
	gpio_control_reg&= ~(1U << MOTOR_ENABLE_BIT);
	printRegister("After CLEAR Motor Enable (Bit 0)6:", gpio_control_reg);
	
	bool is_fault_active = (gpio_control_reg >> SENSOR_FTL_BIT) & 1U;
	std::cout << "Is fault Active(Bit 2)?" << (is_fault_active? "YES" : "NO") << "\n";
	
	return 0;
	
}
