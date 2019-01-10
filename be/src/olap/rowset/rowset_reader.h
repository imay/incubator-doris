// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef DORIS_BE_SRC_OLAP_ROWSET_ROWSET_READER_H
#define DORIS_BE_SRC_OLAP_ROWSET_ROWSET_READER_H

#include "olap/rowset/rowset_reader_context_builder.h"

#include <memory>
#include <unordered_map>

namespace doris {

class RowsetReader;
using RowsetReaderSharedPtr = std::shared_ptr<RowsetReader>;

class RowsetReader {
public:
    static RowsetReader* create();
    virtual ~RowsetReader() { }

    // reader init
    virtual OLAPStatus init(ReaderContext* read_context) = 0;

    // check whether rowset has more data
    virtual bool has_next() = 0;

    // read next block data
    virtual OLAPStatus next(RowCursor* row) = 0;

    // close reader
    virtual void close() = 0;
};

} // namespace doris

#endif // DORIS_BE_SRC_OLAP_ROWSET_ROWSET_READER_H
