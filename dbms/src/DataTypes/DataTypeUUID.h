#pragma once

#include <Columns/ColumnsNumber.h>
#include <DataTypes/DataTypeNumberBase.h>
#include <DataTypes/IDataType.h>
#include <IO/WriteHelpers.h>
#include <IO/ReadHelpers.h>

namespace DB
{

class DataTypeUUID final : public DataTypeNumberBase<UInt128>
{

public:
    bool behavesAsNumber() const override { return false; }

    std::string getName() const override { return "UUID"; }
    const char * getFamilyName() const override { return "UUID"; }
    DataTypePtr clone() const override { return std::make_shared<DataTypeUUID>(); }

    void serializeText(const IColumn & column, size_t row_num, WriteBuffer & ostr) const override;
    void serializeTextEscaped(const IColumn & column, size_t row_num, WriteBuffer & ostr) const override;
    void deserializeTextEscaped(IColumn & column, ReadBuffer & istr) const override;
    void serializeTextQuoted(const IColumn & column, size_t row_num, WriteBuffer & ostr) const override;
    void deserializeTextQuoted(IColumn & column, ReadBuffer & istr) const override;
    void serializeTextJSON(const IColumn & column, size_t row_num, WriteBuffer & ostr, const FormatSettingsJSON &) const override;
    void deserializeTextJSON(IColumn & column, ReadBuffer & istr) const override;
    void serializeTextCSV(const IColumn & column, size_t row_num, WriteBuffer & ostr) const override;
    void deserializeTextCSV(IColumn & column, ReadBuffer & istr, const char delimiter) const override;
};
}
