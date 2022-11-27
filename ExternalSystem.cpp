#include "ExternalSystem.h"

int ExternalSystem::get_fibonacci_by_index(int index) {
	if (index == 0) return 0;
	if (index == 1 || index == 2) return (index - 1);
	return get_fibonacci_by_index(index - 1) + get_fibonacci_by_index(index - 2);
}
