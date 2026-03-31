#include <algorithm>
#include <cstring>
#include <vector>

class str
{
private:
	char *data;
	size_t length;

	void allocate_and_copy(const char *s, size_t len) {
		length = len;
		data = new char[length + 1];
		std::memcpy(data, s, length);
		data[length] = '\0';
	}

public:
	// Default constructor - empty string
	str() : data(nullptr), length(0) {
		data = new char[1];
		data[0] = '\0';
	}

	// Constructor from char
	str(const char &c) : data(nullptr), length(1) {
		data = new char[2];
		data[0] = c;
		data[1] = '\0';
	}

	// Constructor from char*
	str(const char *&& s_) : data(nullptr), length(0) {
		if (s_ != nullptr) {
			length = std::strlen(s_);
			data = new char[length + 1];
			std::memcpy(data, s_, length);
			data[length] = '\0';
		} else {
			data = new char[1];
			data[0] = '\0';
		}
	}

	// Assignment operator from char*
	str &operator=(const char *&& s_) {
		if (data != s_) {
			delete[] data;
			if (s_ != nullptr) {
				length = std::strlen(s_);
				data = new char[length + 1];
				std::memcpy(data, s_, length);
				data[length] = '\0';
			} else {
				length = 0;
				data = new char[1];
				data[0] = '\0';
			}
		}
		return *this;
	}

	// Copy constructor
	str(const str &other) : data(nullptr), length(other.length) {
		data = new char[length + 1];
		std::memcpy(data, other.data, length);
		data[length] = '\0';
	}

	// Copy assignment operator
	str &operator=(const str &other) {
		if (this != &other) {
			delete[] data;
			length = other.length;
			data = new char[length + 1];
			std::memcpy(data, other.data, length);
			data[length] = '\0';
		}
		return *this;
	}

	// Array subscript operator
	char &operator[](size_t pos) {
		return data[pos];
	}

	// Get length
	size_t len() const {
		return length;
	}

	// Join function
	str join(const std::vector<str> &strs) const {
		if (strs.empty()) {
			return str();
		}

		// Calculate total length
		size_t total_len = 0;
		for (size_t i = 0; i < strs.size(); ++i) {
			total_len += strs[i].length;
			if (i < strs.size() - 1) {
				total_len += length;
			}
		}

		// Allocate memory
		str result;
		delete[] result.data;
		result.length = total_len;
		result.data = new char[total_len + 1];

		// Copy data
		size_t pos = 0;
		for (size_t i = 0; i < strs.size(); ++i) {
			std::memcpy(result.data + pos, strs[i].data, strs[i].length);
			pos += strs[i].length;
			if (i < strs.size() - 1) {
				std::memcpy(result.data + pos, data, length);
				pos += length;
			}
		}
		result.data[total_len] = '\0';

		return result;
	}

	// Slice function
	str slice(size_t l, size_t r) const {
		if (l >= length || l >= r) {
			return str();
		}

		size_t end = (r > length) ? length : r;
		size_t slice_len = end - l;

		str result;
		delete[] result.data;
		result.length = slice_len;
		result.data = new char[slice_len + 1];
		std::memcpy(result.data, data + l, slice_len);
		result.data[slice_len] = '\0';

		return result;
	}

	// Destructor
	~str() {
		delete[] data;
	}
};
