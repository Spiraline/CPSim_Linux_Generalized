#ifndef TASK_H__
#define TASK_H__
#include <cstdio>
#include <string.h>
#include <string>
#include <vector>
#include <memory>
#include "ECU.h"
#include "PriorityPolicy.h"

/** This file is engine code of CPSim-Re engine
 * @file Task.h
 * @class Task
 * @author Seonghyeon Park
 * @date 2020-04-01
 * @brief 
 *  Task's Properties
 *  A Task has below properties.
 *  1. Name,
 *  2. Task ID 
 *  3. Period,
 *  4. Deadline,
 *  5. Function Code
 *  6. Best Case Execution Time
 *  7. Worst Case Execution Time
 *  8. Offset
 */

class Task
{
private:
	std::string m_task_name;
	int m_task_id;
	int m_period;
	int m_deadline;
	int m_wcet;
	int m_bcet;
	int m_offset;
	int m_priority;
	bool m_is_read;
	bool m_is_write;
	std::shared_ptr<ECU> m_ecu;
	std::vector<std::string> m_producers_info;
	std::vector<std::string> m_consumers_info;
	std::vector<std::shared_ptr<Task>> m_producers;
	std::vector<std::shared_ptr<Task>> m_consumers;
	PriorityPolicy m_priority_policy;

public:
    /**
     * Constructors and Destructors
     */
	Task();
	// name, period, deadline, wcet, bcet, offset, isRead, isWrite, ecuId
	Task(std::string, int, int, int, int, int, bool, bool, int, PriorityPolicy policy = PriorityPolicy::CPU);

	Task(std::string, int, int, int, int, int, bool, bool, int, std::vector<std::string>, std::vector<std::string>, PriorityPolicy policy = PriorityPolicy::CPU);
	Task(std::string, int, int, int, int, int, bool, bool, int, std::vector<std::shared_ptr<Task>>, std::vector<std::shared_ptr<Task>>, PriorityPolicy policy = PriorityPolicy::CPU);
	~Task();

    /**
     * Getter member functions
     */
	std::string get_task_name();
	int get_task_id();
	int get_period();
	int get_deadline();
	int get_wcet();
	int get_bcet();
	int get_offset();
	int get_priority();
	bool get_is_read();
	bool get_is_write();
	PriorityPolicy get_priority_policy();

	std::vector<std::shared_ptr<Task>> get_producers();
	std::vector<std::shared_ptr<Task>> get_consumers();
	std::vector<std::string> get_producers_info();
	std::vector<std::string> get_consumers_info();
	std::shared_ptr<ECU> get_ECU();
    /**
     * Setter member functions
     */

	void set_task_name(std::string task_name);
	void set_task_id(int task_id);
	void set_period(int period);
	void set_deadline(int deadline);
	void set_wcet(int wcet);
	void set_bcet(int bcet);
	void set_offset(int offset);
	void set_is_read(bool is_read);
	void set_is_write(bool is_write);

	void set_producers(std::vector<std::shared_ptr<Task>>);
	void set_consumers(std::vector<std::shared_ptr<Task>>);
	void set_producers_info(std::vector<std::string>);
	void set_consumers_info(std::vector<std::string>);
	void set_ECU(std::shared_ptr<ECU>);
	void set_priority(int);
	
	void add_task_to_consumers(std::shared_ptr<Task>);
	void add_task_to_producers(std::shared_ptr<Task>);
	void synchronize_producer_consumer_relation();
};

#endif