/*
 * DSPtoMCU.h
 *
 *  Created on: Nov 13, 2024
 *      Author: MSI
 */

#ifndef INC_DSPTOMCU_H_
#define INC_DSPTOMCU_H_

int DSP_I2C_ADDR = 0b0110100;

#define DEVICE_ADDR_IC_1_WRITE	0x68
#define DEVICE_ADDR_IC_1_READ	0x69

typedef unsigned char ADI_REG_TYPE;

#define trapRegAddr1	0x81A
#define trapRegAddr2	0x81B

void SIGMA_WRITE_REGISTER_BLOCK(int devAddress, int regAddr, int length, ADI_REG_TYPE *pData) {
	ADI_REG_TYPE I2C_buffer[2 + length];
    I2C_buffer[0] = (regAddr & 0xFF00) >> 8;  // High byte of the address
    I2C_buffer[1] = (regAddr & 0x00FF);       // Low byte of the address

    // Copy the data into the I2C buffer
    for (int i = 0; i < length; i++) {
        I2C_buffer[2 + i] = pData[i];
    }
    // Transmit the data via I2C
    if (HAL_I2C_Master_Transmit(&hi2c2, DEVICE_ADDR_IC_1_WRITE, I2C_buffer, 2 + length, HAL_MAX_DELAY) == HAL_OK) {
        HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
    } else {
    	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
    }

}

void SIGMA_READ_REGISTER_BYTES(int trapRegAddr, ADI_REG_TYPE* write_buffer, ADI_REG_TYPE* read_buffer) {
    // Transmit the address to the slave (this is the "write" operation)
    HAL_StatusTypeDef transmitStatus = HAL_I2C_Master_Transmit(&hi2c2, DEVICE_ADDR_IC_1_WRITE, write_buffer, 4, HAL_MAX_DELAY);

    if (transmitStatus == HAL_OK) {
    	HAL_I2C_Mem_Read(&hi2c2, DEVICE_ADDR_IC_1_READ, trapRegAddr, I2C_MEMADD_SIZE_16BIT, read_buffer, 3, HAL_MAX_DELAY);
    } else {
        Error_Handler();
    }
}

void DSP_LED_PIN1(GPIO_PinState State) {
	if(State == GPIO_PIN_SET) {
		ADI_REG_TYPE MODE_0_0[4] = {0x00, 0x80, 0x00, 0x00};
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0000, 4, MODE_0_0);			/* SwitchAlg1ison */
	} else if(State == GPIO_PIN_RESET) {
		ADI_REG_TYPE MODE_0_0[4] = {0x00, 0x00, 0x00, 0x00};
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0000, 4, MODE_0_0);			/* SwitchAlg1ison */
	}
}

void DSP_LED_PIN10(GPIO_PinState State) {
	if(State == GPIO_PIN_SET) {
		ADI_REG_TYPE MODE_0_0[4] = {0x00, 0x80, 0x00, 0x00};
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0005, 4, MODE_0_0);			/* SwitchAlg1ison */
	} else if(State == GPIO_PIN_RESET) {
		ADI_REG_TYPE MODE_0_0[4] = {0x00, 0x00, 0x00, 0x00};
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0005, 4, MODE_0_0);			/* SwitchAlg1ison */
	}
}

void DSP_LED_PIN11(GPIO_PinState State) {
	if(State == GPIO_PIN_SET) {
		ADI_REG_TYPE MODE_0_0[4] = {0x00, 0x80, 0x00, 0x00};
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0006, 4, MODE_0_0);			/* SwitchAlg1ison */
	} else if(State == GPIO_PIN_RESET) {
		ADI_REG_TYPE MODE_0_0[4] = {0x00, 0x00, 0x00, 0x00};
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0006, 4, MODE_0_0);			/* SwitchAlg1ison */
	}
}

float DSP_Readback_1() {
	ADI_REG_TYPE read_buffer[3] = {0};
	ADI_REG_TYPE write_buffer[4];
    write_buffer[0] = (trapRegAddr1 & 0xFF00) >> 8; // Byte 0: Address high byte
    write_buffer[1] = (trapRegAddr1 & 0x00FF); 		// Byte 1: Address low byte
    write_buffer[2] = (0xD6 & 0xFF00) >> 8; 		// Byte 2: 000, progCount[10:6]
    write_buffer[3] = (0xD6 & 0x00FF); 				// Byte 3: progCount[5:0], regSel[1:0]

	SIGMA_READ_REGISTER_BYTES(trapRegAddr1, write_buffer, read_buffer);

	int32_t value = (((int32_t)read_buffer[2] << 8) | ((int32_t)read_buffer[1] << 16) | ((int32_t)read_buffer[0] << 24)) >> 8;
	float realval = (float)value / 524288.0f; // x / (1 << 19)

	return realval;
}

float DSP_Readback_2() {
	ADI_REG_TYPE read_buffer[3] = {0};
	ADI_REG_TYPE write_buffer[4];
    write_buffer[0] = (trapRegAddr1 & 0xFF00) >> 8; // Byte 0: Address high byte
    write_buffer[1] = (trapRegAddr1 & 0x00FF); 		// Byte 1: Address low byte
    write_buffer[2] = (0xE2 & 0xFF00) >> 8; 		// Byte 2: 000, progCount[10:6]
    write_buffer[3] = (0xE2 & 0x00FF); 				// Byte 3: progCount[5:0], regSel[1:0]

	SIGMA_READ_REGISTER_BYTES(trapRegAddr1, write_buffer, read_buffer);

	int32_t value = (((int32_t)read_buffer[2] << 8) | ((int32_t)read_buffer[1] << 16) | ((int32_t)read_buffer[0] << 24)) >> 8;
	float realval = (float)value / 524288.0f; // x / (1 << 19)

	return realval;
}

float DSP_Readback_3() {
	ADI_REG_TYPE read_buffer[3] = {0};
	ADI_REG_TYPE write_buffer[4];
    write_buffer[0] = (trapRegAddr1 & 0xFF00) >> 8; // Byte 0: Address high byte
    write_buffer[1] = (trapRegAddr1 & 0x00FF); 		// Byte 1: Address low byte
    write_buffer[2] = (0xEE & 0xFF00) >> 8; 		// Byte 2: 000, progCount[10:6]
    write_buffer[3] = (0xEE & 0x00FF); 				// Byte 3: progCount[5:0], regSel[1:0]

	SIGMA_READ_REGISTER_BYTES(trapRegAddr1, write_buffer, read_buffer);

	int32_t value = (((int32_t)read_buffer[2] << 8) | ((int32_t)read_buffer[1] << 16) | ((int32_t)read_buffer[0] << 24)) >> 8;
	float realval = (float)value / 524288.0f; // x / (1 << 19)

	return realval;
}

float DSP_Readback_4() {
	ADI_REG_TYPE read_buffer[3] = {0};
	ADI_REG_TYPE write_buffer[4];
    write_buffer[0] = (trapRegAddr1 & 0xFF00) >> 8; // Byte 0: Address high byte
    write_buffer[1] = (trapRegAddr1 & 0x00FF); 		// Byte 1: Address low byte
    write_buffer[2] = (0xFA & 0xFF00) >> 8; 		// Byte 2: 000, progCount[10:6]
    write_buffer[3] = (0xFA & 0x00FF); 				// Byte 3: progCount[5:0], regSel[1:0]

	SIGMA_READ_REGISTER_BYTES(trapRegAddr1, write_buffer, read_buffer);

	int32_t value = (((int32_t)read_buffer[2] << 8) | ((int32_t)read_buffer[1] << 16) | ((int32_t)read_buffer[0] << 24)) >> 8;
	float realval = (float)value / 524288.0f; // x / (1 << 19)

	return realval;
}

void DSP_TONE1_ON_OFF(GPIO_PinState State) {
	if(State == GPIO_PIN_SET) {
		ADI_REG_TYPE MODE_0_0[4] = {0x00, 0x00, 0x00, 0xFF};
		ADI_REG_TYPE MODE_0_1[4] = {0x00, 0x2A, 0xAA, 0xAB};
		ADI_REG_TYPE MODE_0_2[4] = {0x00, 0x80, 0x00, 0x00};
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0002, 4, MODE_0_0);			/* sin_lookupAlg19401mask */
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0003, 4, MODE_0_1);			/* sin_lookupAlg19401increment */
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0004, 4, MODE_0_2);			/* sin_lookupAlg19401ison */
	} else if(State == GPIO_PIN_RESET) {
		ADI_REG_TYPE MODE_0_0[4] = {0x00, 0x00, 0x00, 0xFF};
		ADI_REG_TYPE MODE_0_1[4] = {0x00, 0x2A, 0xAA, 0xAB};
		ADI_REG_TYPE MODE_0_2[4] = {0x00, 0x00, 0x00, 0x00};
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0002, 4, MODE_0_0);			/* sin_lookupAlg19401mask */
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0003, 4, MODE_0_1);			/* sin_lookupAlg19401increment */
		SIGMA_WRITE_REGISTER_BLOCK( DEVICE_ADDR_IC_1_WRITE, 0x0004, 4, MODE_0_2);			/* sin_lookupAlg19401ison */
	}
}

void DSP_TONE1_CHANGE_FREQUENCY(float frequency) {
    float sample_rate = 48000.0; // Assuming 48kHz sample rate
    float normalized_freq = frequency / sample_rate; // Normalized frequency (0 to 1)

    // Double the normalized frequency as SigmaStudio seems to scale it this way
    normalized_freq *= 2.0;

    // Convert normalized frequency to 5.23 fixed-point format
    int fixed_point_value = (int)(normalized_freq * (1 << 23)); // Multiply by 2^23

    // Clamp to 28-bit signed integer range
    if (fixed_point_value > (1 << 27) - 1) {
        fixed_point_value = (1 << 27) - 1;
    } else if (fixed_point_value < -(1 << 27)) {
        fixed_point_value = -(1 << 27);
    }

    ADI_REG_TYPE MODE_0_0[4] = {0x00, 0x00, 0x00, 0xFF};

    // Convert the fixed-point value to 4-byte array (big-endian)
    ADI_REG_TYPE MODE_0_1[4];
    MODE_0_1[0] = (fixed_point_value >> 24) & 0xFF;
    MODE_0_1[1] = (fixed_point_value >> 16) & 0xFF;
    MODE_0_1[2] = (fixed_point_value >> 8) & 0xFF;
    MODE_0_1[3] = fixed_point_value & 0xFF;

    ADI_REG_TYPE MODE_0_2[4] = {0x00, 0x80, 0x00, 0x00};

    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1_WRITE, 0x0002, 4, MODE_0_0);
    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1_WRITE, 0x0003, 4, MODE_0_1);
    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1_WRITE, 0x0004, 4, MODE_0_2);
}

void DSP_GAIN1_CHANGE_VALUE(float val) {
    // Convert the float to 5.23 fixed-point format
    int fixed_point_value = (int)(val * (1 << 23));  // Multiply by 2^23

    // Clamp to 28-bit signed integer range (since it's a 5.23 format, we need 28-bit signed numbers)
    if (fixed_point_value > (1 << 27) - 1) {
        fixed_point_value = (1 << 27) - 1;
    } else if (fixed_point_value < -(1 << 27)) {
        fixed_point_value = -(1 << 27);
    }

    // Convert the fixed-point value to 4-byte array (big-endian)
    ADI_REG_TYPE MODE_0_0[4];
    MODE_0_0[0] = (fixed_point_value >> 24) & 0xFF; // Most significant byte
    MODE_0_0[1] = (fixed_point_value >> 16) & 0xFF;
    MODE_0_0[2] = (fixed_point_value >> 8) & 0xFF;
    MODE_0_0[3] = fixed_point_value & 0xFF; // Least significant byte

    // Write the 4-byte value to the DSP register block
    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1_WRITE, 0x0008, 4, MODE_0_0);
}

void DSP_GAIN2_CHANGE_VALUE(float val) {
    // Convert the float to 5.23 fixed-point format
    int fixed_point_value = (int)(val * (1 << 23));  // Multiply by 2^23

    // Clamp to 28-bit signed integer range (since it's a 5.23 format, we need 28-bit signed numbers)
    if (fixed_point_value > (1 << 27) - 1) {
        fixed_point_value = (1 << 27) - 1;
    } else if (fixed_point_value < -(1 << 27)) {
        fixed_point_value = -(1 << 27);
    }

    // Convert the fixed-point value to 4-byte array (big-endian)
    ADI_REG_TYPE MODE_0_0[4];
    MODE_0_0[0] = (fixed_point_value >> 24) & 0xFF; // Most significant byte
    MODE_0_0[1] = (fixed_point_value >> 16) & 0xFF;
    MODE_0_0[2] = (fixed_point_value >> 8) & 0xFF;
    MODE_0_0[3] = fixed_point_value & 0xFF; // Least significant byte

    // Write the 4-byte value to the DSP register block
    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1_WRITE, 0x0016, 4, MODE_0_0);
}

void DSP_GAIN3_CHANGE_VALUE(float val) {
    // Convert the float to 5.23 fixed-point format
    int fixed_point_value = (int)(val * (1 << 23));  // Multiply by 2^23

    // Clamp to 28-bit signed integer range (since it's a 5.23 format, we need 28-bit signed numbers)
    if (fixed_point_value > (1 << 27) - 1) {
        fixed_point_value = (1 << 27) - 1;
    } else if (fixed_point_value < -(1 << 27)) {
        fixed_point_value = -(1 << 27);
    }

    // Convert the fixed-point value to 4-byte array (big-endian)
    ADI_REG_TYPE MODE_0_0[4];
    MODE_0_0[0] = (fixed_point_value >> 24) & 0xFF; // Most significant byte
    MODE_0_0[1] = (fixed_point_value >> 16) & 0xFF;
    MODE_0_0[2] = (fixed_point_value >> 8) & 0xFF;
    MODE_0_0[3] = fixed_point_value & 0xFF; // Least significant byte

    // Write the 4-byte value to the DSP register block
    SIGMA_WRITE_REGISTER_BLOCK(DEVICE_ADDR_IC_1_WRITE, 0x0007, 4, MODE_0_0);
}


#endif /* INC_DSPTOMCU_H_ */
