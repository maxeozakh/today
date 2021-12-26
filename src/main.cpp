#include <iostream>
#include <fstream>
#include <string>

void get_rows_from_txt(const char *path, std::string *out_rows);
void split_rows_to_tasks_and_times(const std::string *rows, std::string *out_tasks, std::string *out_times);

/*
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

task-text --- t-time --- r-text --- r-time 
*/

int main()
{
	const int max_rows = 100;

	std::string rows[max_rows];
	get_rows_from_txt("../assets/tasks.txt", rows);

	std::string tasks[max_rows];
	std::string times[max_rows];
	split_rows_to_tasks_and_times(rows, tasks, times);

	std::cout << "🐕" << '\n';
}

void split_rows_to_tasks_and_times(const std::string *rows, std::string *out_tasks, std::string *out_times)
{
	std::string row, task, time, divider = "--t";

	while (*rows != "")
	{
		row = *rows;
		int divider_position = row.find(divider);

		task = row.substr(0, divider_position - 1);
		time = row.substr(divider_position + divider.length() + 1);

		*out_tasks = task;
		*out_times = time;

		rows++;
		out_tasks++;
		out_times++;
	}
}

void get_rows_from_txt(const char *path, std::string *out_rows)
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
			*out_rows = line;
			out_rows++;
		}
	}
}