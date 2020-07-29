#include <Python.h>
#include "pyhelper.hpp"

// Source: https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code

// CPyInstance

CPyInstance::CPyInstance(const int& argc = 0): argc(argc) {
	Py_Initialize();
}

CPyInstance::CPyInstance(const int& argc, char** argv): CPyInstance(argc) {
	// get wchar_t* array from char* array
	// and save it internally
	this->argv = new wchar_t*[argc];
	for (int i = 0; i < argc; ++i) {
		this->argv[i] = Py_DecodeLocale(argv[i], nullptr);
	}

	PySys_SetArgv(argc, this->argv); // do not update sys in Python
}

CPyInstance::~CPyInstance() {
	for (int i = 0; i < this->argc; ++i) {
		PyMem_RawFree(this->argv[i]);
	}
	delete[] this->argv;

	Py_Finalize();
}


// CPyObject

CPyObject::CPyObject() : p(NULL) {
}

CPyObject::CPyObject(PyObject* _p) : p(_p) {
}

CPyObject::~CPyObject() {
	Release();
}

PyObject* CPyObject::getObject() {
	return p;
}

PyObject* CPyObject::setObject(PyObject* _p) {
	return (p=_p);
}

PyObject* CPyObject::AddRef() {
	if(p) {
		Py_INCREF(p);
	}
	return p;
}

void CPyObject::Release() {
	if(p) {
		Py_DECREF(p);
	}
	p = NULL;
}

PyObject* CPyObject::operator ->() {
	return p;
}

bool CPyObject::is() {
	return (p != NULL) || false;
}

CPyObject::operator PyObject*() {
	return p;
}

PyObject* CPyObject::operator=(PyObject* pp) {
	p = pp;
	return p;
}

CPyObject::operator bool() {
	return (p != NULL) || false;
}

