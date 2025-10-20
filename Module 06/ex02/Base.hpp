#pragma once

// Including the typeinfo header is forbidden.

class Base {
	public:
		virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);
