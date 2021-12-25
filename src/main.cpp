#include <iostream>
#include <fstream>
#include <string>

void read_rows_from_txt(const char *path);

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
	read_rows_from_txt("../assets/tasks.txt");
	std::cout << "🐕" << '\n';
}

void read_rows_from_txt(const char *path)
{
	std::string line;
	std::ifstream file(path);

	if (!file.is_open())
	{
		std::cout << "oops something really bad happens when trying to read file in path - " << path << '\n';
	}
	else
	{
		while (file.good())
		{
			std::getline(file, line);
			std::cout << line << '\n';
		}
	}
}