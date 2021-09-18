#ifndef STR_FUNC_H_
#define STR_FUNC_H_

#include <stddef.h>
#include <stdio.h>

/**
 * @brief   Writes every character from the null-terminated string str 
 *          and one additional newline character '\n' to the output stream stdout,
 *          as if by repeatedly executing fputc.
 *          The terminating null character from str is not written.
 * 
 * @param str character string to be written
 * @return  On success, returns a non-negative value
 *          On failure, returns EOF.
 */
int m_puts(const char *str);

/**
 * @brief   Finds the first occurrence 
 *          of the character in the byte string pointed to by str.
 *          The terminating null character is considered to be a part of the string 
 *          and can be found if searching for '\0'.
 * 
 * @param str pointer to the null-terminated byte string to be analyzed
 * @param ch character to search for
 * @return Pointer to the found character in str, or a null pointer if no such character is found.
 */
const char *m_strchr(const char *str, int ch);

/**
 * @brief   Returns the length of the given byte string, 
 *          that is, the number of characters in a character array 
 *          whose first element is pointed to by str up to and 
 *          not including the first null character. 
 *          The behavior is undefined if there is no null character 
 *          in the character array pointed to by str.
 * 
 * @param str pointer to the null-terminated byte string to be examined
 * @return size_t The length of the null-terminated string str.
 */
size_t m_strlen(const char *str);

/**
 * @brief   Copies the character string pointed to by src, 
 *          including the null terminator, 
 *          to the character array whose first element is pointed to by dest.
 *          The behavior is undefined if the dest array is not large enough. 
 *          The behavior is undefined if the strings overlap.
 * 
 * @param dest 	pointer to the character array to write to
 * @param src   pointer to the null-terminated byte string to copy from
 * @return char* dest
 */
char *m_strcpy(char *dest, const char *src);

/**
 * @brief   Copies at most count characters of the byte string pointed to by src 
 *          (including the terminating null character) 
 *          to character array pointed to by dest.
 *          If count is reached before the entire string src was copied, 
 *          the resulting character array is not null-terminated.
 *          If, after copying the terminating null character from src, count is not reached, 
 *          additional null characters are written to dest 
 *          until the total of count characters have been written.
 *          If the strings overlap, the behavior is undefined.
 * 
 * @param dest pointer to the character array to copy to
 * @param src pointer to the byte string to copy from
 * @param count maximum number of characters to copy
 * @return char* dest
 */
char *m_strncpy(char *dest, const char *src, size_t count);

/**
 * @brief   Appends a copy of the character string pointed to by src 
 *          to the end of the character string pointed to by dest. 
 *          The character src[0] replaces the null terminator at the end of dest. 
 *          The resulting byte string is null-terminated.
 *          The behavior is undefined if the destination array is not large enough 
 *          for the contents of both src and dest and the terminating null character.
 *          The behavior is undefined if the strings overlap.
 * 
 * @param dest pointer to the null-terminated byte string to append to
 * @param src pointer to the null-terminated byte string to copy from
 * @return char* dest
 */
char *m_strcat(char *dest, const char *src);

/**
 * @brief   Appends a byte string pointed to by src to a byte string pointed to by dest. 
 *          At most count characters are copied. 
 *          The resulting byte string is null-terminated.
 *          The destination byte string must have enough space 
 *          for the contents of both dest and src plus the terminating null character, 
 *          except that the size of src is limited to count.
 *          The behavior is undefined if the strings overlap.
 * 
 * @param dest pointer to the null-terminated byte string to append to
 * @param src pointer to the null-terminated byte string to copy from
 * @param count maximum number of characters to copy
 * @return char* dest
 */
char *m_strncat(char *dest, const char *src, size_t count);

/**
 * @brief   Returns a pointer to a null-terminated byte string,
 *          which is a duplicate of the string pointed to by str1. 
 *          The returned pointer must be passed to free to avoid a memory leak.
 *          If an error occurs, a null pointer is returned and errno may be set.
 * 
 * @param str1 pointer to the null-terminated byte string to duplicate
 * @return char* A pointer to the newly allocated string, or a null pointer if an error occurred.
 */
char *m_strdup(const char *str1);

/**
 * @brief   Reads at most count - 1 characters from the given file stream 
 *          and stores them in the character array pointed to by str. 
 *          Parsing stops if a newline character is found, 
 *          in which case str will contain that newline character, 
 *          or if end-of-file occurs. 
 *          If bytes are read and no errors occur, 
 *          writes a null character at the position immediately after the last character 
 *          written to str.
 * 
 * @param str pointer to an element of a char array
 * @param count maximum number of characters to write (typically the length of str)
 * @param stream file stream to read the data from
 * @return char* str on success, null pointer on failure.
 */
char *m_fgets(char *str, int count, FILE *stream);

/**
 * @brief allocates/reallocates memory for m_getline
 * 
 * @param lineptr 
 * @param n 
 * @param new_sz 
 * @return char* (*lineptr) - pointer to allocated/reallocated memory
 */
char *m_getline_realloc(char **lineptr, size_t *n, size_t new_sz);

/**
 * @brief   This function reads an entire line from stream, 
 *          storing the text (including the newline and a terminating null character) 
 *          in a buffer and storing the buffer address in *lineptr.
 *          Before calling getline, you should place in *lineptr 
 *          the address of a buffer *n bytes long, allocated with malloc. 
 *          If this buffer is long enough to hold the line, 
 *          getline stores the line in this buffer. 
 *          Otherwise, getline makes the buffer bigger using realloc, 
 *          storing the new buffer address back in *lineptr and the increased size back in *n.
 * 
 * @param lineptr   ptr to ptr on allocated memory for a resulting string (should be freed after use)
 * @param n         ptr to variable to hold length of resulting string
 * @param stream    stream to read from
 * @return      On success, return the number of
 *              characters read, including the delimiter character, but not
 *              including the terminating null byte ('\0').
 */
ssize_t m_getline(char **lineptr, size_t *n, FILE *stream);

#endif