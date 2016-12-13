/***************************************************************************
   Copyright 2016 Ufora Inc.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
****************************************************************************/
#pragma once

#include <Python.h>

#include "core/PyObjectPtr.hpp"

#include <stdexcept>


class UnresolvedFreeVariableExceptionWithTrace : public std::runtime_error {
public:
    explicit UnresolvedFreeVariableExceptionWithTrace(PyObject* value)
        : std::runtime_error(""),
          mPtr(PyObjectPtr::unincremented(value))
        {
        }

    // returns a borrowed reference
    PyObject* value() const {
        return mPtr.get();
        }

private:
    PyObjectPtr mPtr;
};
