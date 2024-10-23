#ifndef ENCODE_H
#define ENCODE_H

#include "types.h" // Contains user defined types

/* 
 * Structure to store information required for
 * encoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */

/* // Can be removed 
#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4
*/

typedef struct _EncodeInfo
{
    /* Source Image info */
    char *src_image_fname;  // => Store the src_img_fname
    FILE *fptr_src_image;   // => File pointer for src_img
    uint size_image_file;    // => Store the src_img_filesize
    uint bits_per_pixel;
    //char image_data[MAX_IMAGE_BUF_SIZE];
     
    /* Secret File Info */
    char *secret_fname;     // => Store the secret_fname
    FILE *fptr_secret;      // => File pointer for secret_file 
    uint size_secret_file;  // => Store the secret_img_filesize 
    char extn_secret_file[ 5 ] ; 



    /* Stego Image Info */
    char *stego_image_fname;    // => Store the out_img_fname
    FILE *fptr_stego_image;     // => File pointer for output_img 

} EncodeInfo;


/* Encoding function prototype */

/* Check operation type */
OperationType check_operation_type(char *argv[] , int argc );

/* Read and validate Encode args from argv */
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo , int argc );

/* Perform the encoding */
Status do_encoding(EncodeInfo *encInfo);

/* Get File pointers for i/p and o/p files */
Status open_files(EncodeInfo *encInfo);

/* check capacity */
Status check_capacity(EncodeInfo *encInfo);

/* Get image size */
uint get_image_size_for_bmp(FILE *fptr_image);

/* Get file size */
uint get_file_size(FILE *fptr);

/* Copy bmp image header */
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image);

/* Store Magic String */
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo);

/* Encode secret file extenstion size */
Status encode_secret_file_extn_size( long extn_size , EncodeInfo *encInfo);

/* Encode secret file extenstion */
Status encode_secret_file_extn( char *file_extn, EncodeInfo *encInfo);

/* Encode secret file size */
Status encode_secret_file_size(int file_size, EncodeInfo *encInfo);

/* Encode secret file data*/
Status encode_secret_file_data(EncodeInfo *encInfo);

/* Encode function, which does the real encoding */
Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image);

/* Encode the secret file size to image */
Status encode_size_to_lsb( int data , char * buffer );

/* Encode a byte into LSB of image data array */
Status encode_byte_to_lsb(char data, char *image_buffer);

/* Copy remaining image bytes from src to stego image after encoding */
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest);

#endif
