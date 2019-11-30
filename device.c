/*
 * This file is part of OpenCorsairLink.
 * Copyright (C) 2017-2019  Sean Nelson <audiohacked@gmail.com>

 * OpenCorsairLink is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * any later version.

 * OpenCorsairLink is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with OpenCorsairLink.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "device.h"

#include "driver.h"

#include <libusb.h>

//todo this depends on the order of the corsairlink_devices array! if it changes, this breaks!
//todo fix
enum corsair_device_enum {
    H80i_GT = 0,
    H100i_GTX,
    H80,
    Cooling_Node,
    Lighting_Node,
    H100,
    H80i,
    H100i,
    Commander_Mini,
    H100i_GT,
    H110i_GT,
    H110i,
    H110i_GTX,
    H80i_GT_V2,
    H100i_GT_V2,
    H110i_GT_V2,
    Lighting_Node_PRO,
    Commander_PRO,
    Obsidian_1000D_Commander_Pro,
    H150i_Pro,
    H115i_Pro,
    H110i_Pro,
    H100i_Pro,
    H80i_Pro,
    USB_Dongle,
    AX1500i,
    HX550i,
    HX650i,
    HX750i,
    HX850i,
    HX1000i,
    HX1200i,
    RM550i,
    RM650i,
    RM750i,
    RM850i,
    RM1000i,
    AX850i,
    AX1000i,
    AX1200i,
    AX1600i,
    CORSAIR_DEVICE_MAX
};

struct corsair_device_info corsairlink_devices[] = {
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c02,
        .device_id = 0xFF,
        .name = "H80i GT",
        .read_endpoint = 0x02 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x02 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_asetek,
        .led_control_count = 1,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c03,
        .device_id = 0xFF,
        .name = "H100i GTX",
        .read_endpoint = 0x02 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x02 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_asetek,
        .led_control_count = 1,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c04,
        .device_id = 0x37,
        .name = "H80",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint =
            LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_coolit,
        .led_control_count = 1,
        .fan_control_count = 4,
        .temperature_control_count = 4,
        .pump_index = 5,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c04,
        .device_id = 0x38,
        .name = "Cooling Node",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint =
            LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_coolit,
        .led_control_count = 1,
        .fan_control_count = 4,
        .temperature_control_count = 4,
        .pump_index = 5,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c04,
        .device_id = 0x39,
        .name = "Lighting Node",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint =
            LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_coolit,
        .led_control_count = 1,
        .fan_control_count = 4,
        .pump_index = 5,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c04,
        .device_id = 0x3a,
        .name = "H100",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint =
            LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_coolit,
        .led_control_count = 1,
        .fan_control_count = 4,
        .temperature_control_count = 4,
        .pump_index = 5,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c04,
        .device_id = 0x3b,
        .name = "H80i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint =
            LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_coolit,
        .led_control_count = 1,
        .fan_control_count = 4,
        .pump_index = 5,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c04,
        .device_id = 0x3c,
        .name = "H100i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint =
            LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_coolit,
        .led_control_count = 1,
        .fan_control_count = 4,
        .pump_index = 5,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c04,
        .device_id = 0x3d,
        .name = "Commander Mini", /** Whiptail */
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint =
            LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_coolit,
        .led_control_count = 1,
        .fan_control_count = 4,
        .pump_index = 5,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c04,
        .device_id = 0x40,
        .name = "H100i GT", /** H100i */
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint =
            LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_coolit,
        .led_control_count = 1,
        .fan_control_count = 4,
        .pump_index = 5,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c04,
        .device_id = 0x41,
        .name = "H110i GT", /** H110i GT*/
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint =
            LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_coolit,
        .led_control_count = 1,
        .fan_control_count = 2,
        .pump_index = 3,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c04,
        .device_id = 0x42,
        .name = "H110i", /** H110i */
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint =
            LIBUSB_REQUEST_TYPE_CLASS | LIBUSB_RECIPIENT_INTERFACE | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_coolit,
        .led_control_count = 1,
        .fan_control_count = 2,
        .pump_index = 2,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c07,
        .device_id = 0xFF,
        .name = "H110i GTX", /** H110i GTX */
        .read_endpoint = 0x02 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x02 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_asetek,
        .led_control_count = 1,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c08,
        .device_id = 0xFF,
        .name = "H80i GT V2", /** H80i V2 */
        .read_endpoint = 0x02 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x02 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_asetek, // 2
        .led_control_count = 1,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c09,
        .device_id = 0xFF,
        .name = "H100i GT V2", /** H100i V2 */
        .read_endpoint = 0x02 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x02 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_asetek, // 2
        .led_control_count = 1,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c0a,
        .device_id = 0xFF,
        .name = "H110i GT V2", /** H110i V2 */
        .read_endpoint = 0x02 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x02 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_asetek, // 2
        .led_control_count = 1,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c0b,
        .device_id = 0xFF,
        .name = "Lighting Node PRO", /* Antigua */
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x02 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_commanderpro,
        .led_control_count = 2,
        .fan_control_count = 6,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c10,
        .device_id = 0xFF,
        .name = "Commander PRO", /* Barbuda */
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x02 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_commanderpro,
        .led_control_count = 2,
        .fan_control_count = 6,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1d00,
        .device_id = 0xFF,
        .name = "Obsidian 1000D Commander Pro",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x02 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_commanderpro,
        .led_control_count = 2,
        .fan_control_count = 6,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c12,
        .device_id = 0xFF,
        .name = "H150i Pro",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_asetekpro,
        .led_control_count = 1,
        .fan_control_count = 3,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c13,
        .device_id = 0xFF,
        .name = "H115i Pro",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_asetekpro,
        .led_control_count = 1,
        .fan_control_count = 2,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c14,
        .device_id = 0xFF,
        .name = "H110i Pro",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_asetekpro,
        .led_control_count = 1,
        .fan_control_count = 2,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c15,
        .device_id = 0xFF,
        .name = "H100i Pro",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_asetekpro,
        .led_control_count = 1,
        .fan_control_count = 2,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c16,
        .device_id = 0xFF,
        .name = "H80i Pro",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_asetekpro,
        .led_control_count = 1,
        .fan_control_count = 2,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c00,
        .device_id = 0xFF,
        .name = "USB Dongle",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_dongle,
        .led_control_count = 1,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c02,
        .device_id = 0xFF,
        .name = "AX1500i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_dongle,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c03,
        .device_id = 0xFF,
        .name = "HX550i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_rmi,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c04,
        .device_id = 0xFF,
        .name = "HX650i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_rmi,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c05,
        .device_id = 0xFF,
        .name = "HX750i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_rmi,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c06,
        .device_id = 0xFF,
        .name = "HX850i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_rmi,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c07,
        .device_id = 0xFF,
        .name = "HX1000i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_rmi,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c08,
        .device_id = 0xFF,
        .name = "HX1200i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_rmi,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c09,
        .device_id = 0xFF,
        .name = "RM550i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_rmi,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c0a,
        .device_id = 0xFF,
        .name = "RM650i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_rmi,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c0b,
        .device_id = 0xFF,
        .name = "RM750i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_rmi,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c0c,
        .device_id = 0xFF,
        .name = "RM850i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_rmi,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c0d,
        .device_id = 0xFF,
        .name = "RM1000i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_rmi,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c0e,
        .device_id = 0xFF,
        .name = "AX850i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_dongle,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c0f,
        .device_id = 0xFF,
        .name = "AX1000i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_dongle,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c10,
        .device_id = 0xFF,
        .name = "AX1200i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_dongle,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x1c11,
        .device_id = 0xFF,
        .name = "AX1600i",
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x01 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_dongle,
        .led_control_count = 0,
        .fan_control_count = 1,
        .pump_index = 0,
    },
};

uint8_t corsairlink_device_list_count =
    sizeof( corsairlink_devices ) / sizeof( corsairlink_devices[0] );
