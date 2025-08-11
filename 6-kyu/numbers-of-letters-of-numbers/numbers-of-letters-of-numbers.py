def numbers_of_letters(n):
​
    string_numbers = {
     0 :'zero',
     1:'one',
     2: 'two',
     3: 'three',
     4: 'four', 
     5: 'five',
     6: 'six', 
     7 : 'seven',
     8 : 'eight',
     9: 'nine'
}
​
    result_list = []
​
    word_digits = [string_numbers[int(digit)] for digit in str(n)]
    concat_digits = "".join(word_digits)
​
    while concat_digits != "four" :
        result_list.append(concat_digits)
        letter_count = len(concat_digits)
        word_digits = [string_numbers[int(digit)] for digit in str(letter_count)]
        concat_digits = "".join(word_digits)
​
    result_list.append("four")
​
    return result_list