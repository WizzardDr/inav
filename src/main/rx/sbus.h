/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define SBUS_DEFAULT_INTERFRAME_DELAY_US    3000    // According to FrSky interframe is 6.67ms, we go smaller just in case

#include "rx/rx.h"

bool sbusInit(const rxConfig_t *initialRxConfig, rxRuntimeConfig_t *rxRuntimeConfig);
bool sbusInitFast(const rxConfig_t *initialRxConfig, rxRuntimeConfig_t *rxRuntimeConfig);

#define SBUS_BYTE_TIME_US(bytes)    MS2US(10 * 12 * bytes) // 10us per bit * (1 start + 8 data + 1 parity + 2 stop) * number of bytes

#ifdef USE_TELEMETRY_SBUS2
uint8_t sbusGetCurrentTelemetryPage(void);
uint8_t sbusGetCurrentTelemetryNextSlot(void);
timeUs_t sbusGetLastFrameTime(void);
#endif
