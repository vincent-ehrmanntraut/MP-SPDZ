/*
 * SubDataFilesBase.h
 *
 */

#ifndef PROCESSOR_PREPBASE_H_
#define PROCESSOR_PREPBASE_H_

#include <string>
using namespace std;

#include "Math/field_types.h"
#include "Tools/TimerWithComm.h"

class DataPositions;

class PrepBase
{
protected:
    DataPositions& usage;

public:
    static string get_suffix(int thread_num);

    static string get_filename(const string& prep_data_dir, Dtype type,
            const string& type_short, int my_num, int thread_num = 0);
    static string get_input_filename(const string& prep_data_dir,
            const string& type_short, int input_player, int my_num,
            int thread_num = 0);
    static string get_edabit_filename(const string& prep_data_dir, int n_bits,
            int my_num, int thread_num = 0);

    static string get_matrix_prefix(const string& prep_data_dir,
            const array<int, 3>& dim);

    TimerWithComm prep_timer;

    PrepBase(DataPositions& usage);

    void print_left(const char* name, size_t n,
            const string& type_string, size_t used, bool large = false);

    void print_left_edabits(size_t n, size_t n_batch, bool strict,
            int n_bits, size_t used, bool malicious);
};

#endif /* PROCESSOR_PREPBASE_H_ */
