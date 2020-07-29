#ifndef PYHELPER_HPP
#define PYHELPER_HPP
#pragma once

#include <Python.h>

// Source: https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code

class CPyInstance {
	private:
		const int argc;
		wchar_t** argv = nullptr;
	public:
		CPyInstance(const int& argc);
		CPyInstance(const int& argc, char** argv);
		~CPyInstance();
};


class CPyObject {
	private:
		PyObject *p;
	public:
		CPyObject();
		CPyObject(PyObject* _p);
		~CPyObject();
		PyObject* getObject();
		PyObject* setObject(PyObject* _p);
		PyObject* AddRef();
		void Release();
		PyObject* operator->();
		bool is();
		operator PyObject*();
		PyObject* operator=(PyObject* pp);
		operator bool();
};


#endif
