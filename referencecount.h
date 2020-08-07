#pragma once
class refcount
{
private:
	int count = 0;
public:
	refcount() {}
	~refcount() {}
	void addref() { count++; }

	int release(){ return count--; }
	int getrefcount()
	{
		return count;
	}
};