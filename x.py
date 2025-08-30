import crcmod

def demonstrate_crc():
    # Create a CRC-16 function (you can modify parameters as needed)
    crc16 = crcmod.mkCrcFun(0x11021, initCrc=0xFFFF, rev=False, xorOut=0x0000)
    
    # Original message
    message = b"Hello, World!"
    print(f"Original message: {message}")
    
    # Calculate CRC for the message
    crc = crc16(message)
    print(f"CRC value: {hex(crc)}")
    
    # Convert CRC to bytes (2 bytes for CRC-16)
    crc_bytes = crc.to_bytes(2, byteorder='big')
    
    # Append CRC to message
    message_with_crc = message + crc_bytes
    print(f"Message with CRC: {message_with_crc}")
    print(f"Message with CRC (hex): {message_with_crc.hex()}")
    
    # Verify: calculating CRC of the entire message (including CRC bytes) should give 0
    final_crc = crc16(message_with_crc)
    print(f"\nVerification CRC: {hex(final_crc)}")
    print(f"Verification successful: {final_crc == 0}")
    
    # Demonstrate error detection
    # Modify one byte in the message
    corrupted_message = bytearray(message_with_crc)
    corrupted_message[2] = (corrupted_message[2] + 1) % 256  # Change one byte
    
    # Calculate CRC of corrupted message
    corrupted_crc = crc16(corrupted_message)
    print(f"\nCorrupted message CRC: {hex(corrupted_crc)}")
    print(f"Error detected: {corrupted_crc != 0}")

if __name__ == "__main__":
    demonstrate_crc()