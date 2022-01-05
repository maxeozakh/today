#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "main.hpp"

std::string color_codes[] = {"97", "92"};

void insert_string_to_the_line(const char *file_path, std::string inserted_string, const int &line_number)
{

	std::fstream file(file_path);
        if (!file.is_open())
        {   
                std::cout << "smthg happens when trying to open file: " << file_path << '\n';
                return; 
        }   

        std::string line;
	std::string virtual_strings[100];
	int lines_in_file = 0;
        while (std::getline(file, line))
        {   
		virtual_strings[lines_in_file] = line + '\n';
		lines_in_file++;
        } 
	
	file.clear();
	file.seekg(0);
	

	virtual_strings[line_number] = inserted_string + '\n';  
	
	for (int i = 0; i < lines_in_file; i++)
	{
		file << virtual_strings[i];
	}
}

std::string get_line_by_line_number(const char *file_path, const int &line_number)
{
	std::fstream file(file_path);

        if (!file.is_open())
        {   
                std::cout << "smthg happens when trying to open file: " << file_path << '\n';
                return "";
        }   
        unsigned int line_counter = 0;
        std::string line;
        while (line_counter < line_number)
        {   
                file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                line_counter++;
        }   
        file.seekp(file.tellg());
	std::getline(file, line);
	
        return line;
}


int main()
{
	const int MAX_ROWS = 100;
	const char *FILE_PATH = "../assets/tasks.txt";
	const char *TEST_FP = "../assets/test.txt";

	std::string rows[MAX_ROWS];
		
	insert_string_to_the_line(TEST_FP, "hello there", 2);
	
	get_rows_from_txt(TEST_FP, rows);

	std::string tasks[MAX_ROWS], times[MAX_ROWS];
	split_rows_to_tasks_and_times(rows, tasks, times);

	std::string formatted_tasks[MAX_ROWS], formatted_times[MAX_ROWS];
	format_data_for_column(tasks, formatted_tasks, 30);
	format_data_for_column(times, formatted_times, 5);

	print_columns_as_rows(formatted_tasks, formatted_times);
	std::cout << '\n' <<  "🐕" << '\n';

	return 0;
}

void color_print(std::string &value, colors color)
{
	std::cout << "\033[" << color_codes[color] << "m" << value << "\033[0m\n";
}

void *print_columns_as_rows(std::string *tasks, std::string *times)
{
	while (*tasks != "")
	{
		std::cout << *tasks << *times << '\n';

		tasks++;
		times++;
	}
}

void format_data_for_column(const std::string *raw_data, std::string *out_formatted_data, const int &column_length)
{
	std::string row, formatted_row;
	while (*raw_data != "")
	{
		row = *raw_data;
		int additional_spaces_count = column_length - row.length();

		if (additional_spaces_count < 0)
		{
			std::cout << "oooooops, raw row is too long, dont wanna format that \n";
			std::cout << "row: " << row << '\n';
			additional_spaces_count = 0;
		}

		*out_formatted_data = row.append(additional_spaces_count, ' ');
		out_formatted_data++;
		raw_data++;
	}
}

void split_rows_to_tasks_and_times(const std::string *rows, std::string *out_tasks, std::string *out_times)
{
	std::string row, task, time, divider = "--t";

	while (*rows != "")
	{
		row = *rows;
		int divider_position = row.find(divider);
		if (divider_position == -1)
		{
			task = row;
			time = "";	
		}
		else {
			task = row.substr(0, divider_position - 1);
			time = row.substr(divider_position + divider.length() + 1);
		}


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
		return;
	}

	while (file.good())
	{
		std::getline(file, line);
		*out_rows = line;
		out_rows++;
	}
}
