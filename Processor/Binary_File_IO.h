#ifndef _FILE_IO_HEADER
#define _FILE_IO_HEADER

#include "Tools/Exceptions.h"

#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

/* 
 * Provides generalised file read and write methods for arrays of numeric data types.
 * Stateless and not optimised for multiple reads from file.
 * Intended for MPC application specific file IO.
 */

template<class T>
class Binary_File_IO
{
  public:

  static string filename(int my_number);
  static void reset(int my_number);

  /*
   * Append the buffer values as binary to the filename.
   * Throws file_error.   
   */
  void write_to_file(const string filename, const vector<T>& buffer,
      long start_pos);

  /*
   * Read from posn in the filename the binary values until the buffer is full.
   * Assumes file holds binary that maps into the type passed in.
   * Returns the current posn in the file or -1 if at eof.
   * Throws file_error.
   */
  void read_from_file(const string filename, vector<T>& buffer,
      const long start_posn, long& end_posn);
};

#endif
