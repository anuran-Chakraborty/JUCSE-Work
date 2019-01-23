import sender as se
import receiver as re
import errorchecker as err

# Main module to show all 3 cases
print('--------------------------------------------------------------------------')
list_of_frames=(se.readfile('input.txt',no_of_bits=err.no_of_bits))
print('Case1: All 4 schemes can detect the error')
se.dataword_to_codeword(list_of_frames,no_of_bits=err.no_of_bits, error_list_frames=[0, 1], error_bit_list=[[6], [4]])
re.combiner()
print('--------------------------------------------------------------------------')

print('--------------------------------------------------------------------------')
list_of_frames=(se.readfile('input.txt',no_of_bits=err.no_of_bits))
print('Case2: Error detected by checksum but not by crc')
se.dataword_to_codeword(list_of_frames,no_of_bits=err.no_of_bits, error_list_frames=[0], error_bit_list=[[0, 4, 7]])
re.combiner()
print('--------------------------------------------------------------------------')

print('--------------------------------------------------------------------------')
list_of_frames=(se.readfile('input.txt',no_of_bits=err.no_of_bits))
print('Case3: Error detected by VRC not by CRC')
se.dataword_to_codeword(list_of_frames,no_of_bits=err.no_of_bits, error_list_frames=[1], error_bit_list=[[0, 4, 7]])
re.combiner()
print('--------------------------------------------------------------------------')