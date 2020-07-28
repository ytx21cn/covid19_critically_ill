#include <Python.h>
#include "pyhelper.hpp"

// Source: https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code

// CPyInstance

CPyInstance::CPyInstance() {
	Py_Initialize();
}

CPyInstance::~CPyInstance() {
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

