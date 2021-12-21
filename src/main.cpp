#include <iostream>

void read_rows_from_txt(const char *path, int &out_array);
void split_rows_to_texts_and_times(const char *rows, char *out_texts, char *out_times);
void format_data_for_text_column(const char *raw_data, char *out_formatted_data);
void format_data_for_time_column(const char *raw_data, char *out_formatted_data);
const char *make_row(const char *task_text, 
							const char *task_time, 
							const char *routine_text, 
							const char *routine_time);
void print_rows(const char *tasks_text,
								const char *tasks_time,
								const char *routinies_text,
								const char *routinies_time);

// task-text --- t-time --- r-text --- r-time //

int main() 
{
	std::cout << "🐕" << '\n';
}
