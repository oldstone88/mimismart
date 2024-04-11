#!/usr/bin/env python3
import sys
from pyModbusTCP.client import ModbusClient
try:
    hex_string = sys.argv[3]
    bytes_obj = bytes.fromhex(hex_string)
    result_string = bytes_obj.decode('utf-8')
    data = result_string.split("|")
    c = ModbusClient(host=data[0], port=502, unit_id=1, auto_open=True)
    c.write_single_register(3000+int(data[1])*5, int(data[2][:data[2].find("\x00")]))
    print(f"Changed state of EcoDim device - id: {data[1]} brightness: {data[2]}")
except Exception as ex:
    print("Usage: script.sh <path> <path> <id:sid> <№device 0-63> <brightess value 0-250>")
    print(ex)
