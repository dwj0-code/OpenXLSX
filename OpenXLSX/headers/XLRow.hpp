/*

   ____                               ____      ___ ____       ____  ____      ___
  6MMMMb                              `MM(      )M' `MM'      6MMMMb\`MM(      )M'
 8P    Y8                              `MM.     d'   MM      6M'    ` `MM.     d'
6M      Mb __ ____     ____  ___  __    `MM.   d'    MM      MM        `MM.   d'
MM      MM `M6MMMMb   6MMMMb `MM 6MMb    `MM. d'     MM      YM.        `MM. d'
MM      MM  MM'  `Mb 6M'  `Mb MMM9 `Mb    `MMd       MM       YMMMMb     `MMd
MM      MM  MM    MM MM    MM MM'   MM     dMM.      MM           `Mb     dMM.
MM      MM  MM    MM MMMMMMMM MM    MM    d'`MM.     MM            MM    d'`MM.
YM      M9  MM    MM MM       MM    MM   d'  `MM.    MM            MM   d'  `MM.
 8b    d8   MM.  ,M9 YM    d9 MM    MM  d'    `MM.   MM    / L    ,M9  d'    `MM.
  YMMMM9    MMYMMM9   YMMMM9 _MM_  _MM_M(_    _)MM_ _MMMMMMM MYMMMM9 _M(_    _)MM_
            MM
            MM
           _MM_

  Copyright (c) 2018, Kenneth Troldal Balslev

  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  - Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
  - Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
  - Neither the name of the author nor the
    names of any contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#ifndef OPENXLSX_XLROW_HPP
#define OPENXLSX_XLROW_HPP

#ifdef _MSC_VER    // conditionally enable MSVC specific pragmas to avoid other compilers warning about unknown pragmas
#   pragma warning(push)
#   pragma warning(disable : 4251)
#   pragma warning(disable : 4275)
#endif // _MSC_VER

// ===== OpenXLSX Includes ===== //
#include "OpenXLSX-Exports.hpp"
#include "XLRowData.hpp"

// ========== CLASS AND ENUM TYPE DEFINITIONS ========== //
namespace OpenXLSX
{
    class XLRowRange;

    /**
     * @brief The XLRow class represent a row in an Excel spreadsheet. Using XLRow objects, various row formatting
     * options can be set and modified.
     */
    class OPENXLSX_EXPORT XLRow
    {
        friend class XLRowIterator;
        friend class XLRowDataProxy;
        friend bool operator==(const XLRow& lhs, const XLRow& rhs);
        friend bool operator!=(const XLRow& lhs, const XLRow& rhs);
        friend bool operator<(const XLRow& lhs, const XLRow& rhs);
        friend bool operator>(const XLRow& lhs, const XLRow& rhs);
        friend bool operator<=(const XLRow& lhs, const XLRow& rhs);
        friend bool operator>=(const XLRow& lhs, const XLRow& rhs);

        //---------- PUBLIC MEMBER FUNCTIONS ----------//
    public:
        /**
         * @brief Default constructor
         */
        XLRow();

        /**
         * @brief
         * @param rowNode
         * @param sharedStrings
         */
        XLRow(const XMLNode& rowNode, const XLSharedStrings& sharedStrings);

        /**
         * @brief Copy Constructor
         * @note The copy constructor is explicitly deleted
         */
        XLRow(const XLRow& other);

        /**
         * @brief Move Constructor
         * @note The move constructor has been explicitly deleted.
         */
        XLRow(XLRow&& other) noexcept;

        /**
         * @brief Destructor
         * @note The destructor has a default implementation.
         */
        ~XLRow();

        /**
         * @brief Copy assignment operator.
         * @note The copy assignment operator is explicitly deleted.
         */
        XLRow& operator=(const XLRow& other);

        /**
         * @brief Move assignment operator.
         * @note The move assignment operator has been explicitly deleted.
         */
        XLRow& operator=(XLRow&& other) noexcept;

        /**
         * @brief test if row object has no (valid) content
         * @return
         */
        bool empty() const;

        /**
         * @brief opposite of empty()
         * @return
         */
        explicit operator bool() const;

        /**
         * @brief Get the height of the row.
         * @return the row height.
         */
        double height() const;

        /**
         * @brief Set the height of the row.
         * @param height The height of the row.
         */
        void setHeight(float height);

        /**
         * @brief Get the descent of the row, which is the vertical distance in pixels from the bottom of the cells
         * in the current row to the typographical baseline of the cell content.
         * @return The row descent.
         */
        float descent() const;

        /**
         * @brief Set the descent of the row, which is he vertical distance in pixels from the bottom of the cells
         * in the current row to the typographical baseline of the cell content.
         * @param descent The row descent.
         */
        void setDescent(float descent);

        /**
         * @brief Is the row hidden?
         * @return The state of the row.
         */
        bool isHidden() const;

        /**
         * @brief Set the row to be hidden or visible.
         * @param state The state of the row.
         */
        void setHidden(bool state);

        /**
         * @brief
         * @return
         */
        uint32_t rowNumber() const;

        /**
         * @brief Get the number of cells in the row.
         * @return The number of cells in the row.
         */
        uint16_t cellCount() const;

        /**
         * @brief
         * @return
         */
        XLRowDataProxy& values();

        /**
         * @brief
         * @return
         */
        const XLRowDataProxy& values() const;

        /**
         * @brief
         * @tparam T
         * @return
         */
        template<typename T>
        T values() const
        {
            return static_cast<T>(values());
        }

        /**
         * @brief
         * @return
         */
        XLRowDataRange cells() const;

        /**
         * @brief
         * @param cellCount
         * @return
         */
        XLRowDataRange cells(uint16_t cellCount) const;

        /**
         * @brief
         * @param firstCell
         * @param lastCell
         * @return
         */
        XLRowDataRange cells(uint16_t firstCell, uint16_t lastCell) const;

        /**
         * @brief Find a cell at columNumber, or return an empty cell
         * @param columNumber The column at which to check for an existing cell
         * @return An XLCell object (that bool-evaluates to false if cell was not found)
         */
        XLCell findCell(uint16_t columNumber);

        /**
         * @brief Get the array index of xl/styles.xml:<styleSheet>:<cellXfs> for the style assigned to the row.
         *        This value is stored in the row attributes like so: s="2"
         * @returns The index of the applicable format style
         */
        XLStyleIndex format() const;

        /**
         * @brief Set the row style as a reference to the array index of xl/styles.xml:<styleSheet>:<cellXfs>
         * @param cellFormatIndex The style to set, corresponding to the index of XLStyles::cellStyles()
         * @returns true on success, false on failure
         */
        bool setFormat(XLStyleIndex cellFormatIndex);

    private:
        /**
         * @brief
         * @param lhs
         * @param rhs
         * @return
         */
        static bool isEqual(const XLRow& lhs, const XLRow& rhs);

        /**
         * @brief
         * @param lhs
         * @param rhs
         * @return
         */
        static bool isLessThan(const XLRow& lhs, const XLRow& rhs);

        //---------- PRIVATE MEMBER VARIABLES ----------//
        std::unique_ptr<XMLNode> m_rowNode;       /**< The XMLNode object for the row. */
        XLSharedStringsRef       m_sharedStrings; /**< */
        XLRowDataProxy           m_rowDataProxy;  /**< */
    };

    /**
     * @brief
     */
    class OPENXLSX_EXPORT XLRowIterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type        = XLRow;
        using difference_type   = int64_t;
        using pointer           = XLRow*;
        using reference         = XLRow&;

        /**
         * @brief
         * @param rowRange
         * @param loc
         */
        explicit XLRowIterator(const XLRowRange& rowRange, XLIteratorLocation loc);

        /**
         * @brief
         */
        ~XLRowIterator();

        /**
         * @brief
         * @param other
         */
        XLRowIterator(const XLRowIterator& other);

        /**
         * @brief
         * @param other
         */
        XLRowIterator(XLRowIterator&& other) noexcept;

        /**
         * @brief
         * @param other
         * @return
         */
        XLRowIterator& operator=(const XLRowIterator& other);

        /**
         * @brief
         * @param other
         * @return
         */
        XLRowIterator& operator=(XLRowIterator&& other) noexcept;

    private:    // ===== Switch to private method that is used by the XLRowIterator increment operator++ and the dereference operators * and ->
        static constexpr const bool XLCreateIfMissing      = true;     // code readability for updateCurrentRow parameter createIfMissing
        static constexpr const bool XLDoNotCreateIfMissing = false;    //   "
        /**
         * @brief update m_currentRow by fetching (or inserting) a row at m_currentRowNumber
         * @param createIfMissing m_currentRow will only be inserted if createIfMissing is true
         */
        void updateCurrentRow(bool createIfMissing);

    public:     // ===== Switch back to public methods

        /**
         * @brief
         * @return
         */
        XLRowIterator& operator++();

        /**
         * @brief
         * @return
         */
        XLRowIterator operator++(int);    // NOLINT

        /**
         * @brief
         * @return
         */
        reference operator*();

        /**
         * @brief
         * @return
         */
        pointer operator->();

        /**
         * @brief
         * @param rhs
         * @return
         */
        bool operator==(const XLRowIterator& rhs) const;

        /**
         * @brief
         * @param rhs
         * @return
         */
        bool operator!=(const XLRowIterator& rhs) const;

        /**
         * @brief
         * @return
         */
        explicit operator bool() const;

        /**
         * @brief determine whether the row that the iterator points to exists (m_currentRowNumber)
         * @return true if XML already has an entry for that cell, otherwise false
         */
        bool rowExists();

        /**
         * @brief determine whether iterator is at 1 beyond the last row in range
         * @return
         */
        bool endReached() const { return m_endReached; }

        /**
         * @brief get the row number corresponding to the current iterator position
         * @return a row number, with m_lastRow + 1 for the beyond-the-end iterator
         */
        uint32_t rowNumber() const { return m_endReached ? m_lastRow + 1 : m_currentRowNumber; }

    private:
        std::unique_ptr<XMLNode> m_dataNode;       /**< */
        uint32_t                 m_firstRow { 1 }; /**< The cell reference of the first cell in the range */
        uint32_t                 m_lastRow { 1 };  /**< The cell reference of the last cell in the range */
        XLRow                    m_currentRow;     /**< */
        XLSharedStringsRef       m_sharedStrings;  /**< */

        // helper variables for non-creating iterator functionality
        bool                     m_endReached;           /**< */
        XMLNode                  m_hintRow;              /**< The cell node of the last existing row found up to current iterator position */
        uint32_t                 m_hintRowNumber;        /**<   the row number for m_hintRow */
        static constexpr const int XLNotLoaded  = 0;    // code readability for m_currentRowStatus
        static constexpr const int XLNoSuchRow  = 1;    //   "
        static constexpr const int XLLoaded     = 2;    //   "
        int                      m_currentRowStatus;    /**< Status of m_currentRow: XLNotLoaded, XLNoSuchRow or XLLoaded */
        uint32_t                 m_currentRowNumber;
    };

    /**
     * @brief
     */
    class OPENXLSX_EXPORT XLRowRange
    {
        friend class XLRowIterator;

        //----------------------------------------------------------------------------------------------------------------------
        //           Public Member Functions
        //----------------------------------------------------------------------------------------------------------------------

    public:
        /**
         * @brief
         * @param dataNode
         * @param first
         * @param last
         * @param sharedStrings
         */
        explicit XLRowRange(const XMLNode& dataNode, uint32_t first, uint32_t last, const XLSharedStrings& sharedStrings);

        /**
         * @brief
         * @param other
         */
        XLRowRange(const XLRowRange& other);

        /**
         * @brief
         * @param other
         */
        XLRowRange(XLRowRange&& other) noexcept;

        /**
         * @brief
         */
        ~XLRowRange();

        /**
         * @brief
         * @param other
         * @return
         */
        XLRowRange& operator=(const XLRowRange& other);

        /**
         * @brief
         * @param other
         * @return
         */
        XLRowRange& operator=(XLRowRange&& other) noexcept;

        /**
         * @brief
         * @return
         */
        uint32_t rowCount() const;

        /**
         * @brief
         * @return
         */
        XLRowIterator begin();

        /**
         * @brief
         * @return
         */
        XLRowIterator end();

        //----------------------------------------------------------------------------------------------------------------------
        //           Private Member Variables
        //----------------------------------------------------------------------------------------------------------------------

    private:
        std::unique_ptr<XMLNode> m_dataNode;      /**< */
        uint32_t                 m_firstRow;      /**< The cell reference of the first cell in the range */
        uint32_t                 m_lastRow;       /**< The cell reference of the last cell in the range */
        XLSharedStringsRef       m_sharedStrings; /**< */
    };

}    // namespace OpenXLSX

// ========== FRIEND FUNCTION IMPLEMENTATIONS ========== //
namespace OpenXLSX
{
    /**
     * @brief
     * @param lhs
     * @param rhs
     * @return
     */
    inline bool operator==(const XLRow& lhs, const XLRow& rhs) { return XLRow::isEqual(lhs, rhs); }

    /**
     * @brief
     * @param lhs
     * @param rhs
     * @return
     */
    inline bool operator!=(const XLRow& lhs, const XLRow& rhs) { return !(lhs.m_rowNode == rhs.m_rowNode); }

    /**
     * @brief
     * @param lhs
     * @param rhs
     * @return
     */
    inline bool operator<(const XLRow& lhs, const XLRow& rhs) { return XLRow::isLessThan(lhs, rhs); }

    /**
     * @brief
     * @param lhs
     * @param rhs
     * @return
     */
    inline bool operator>(const XLRow& lhs, const XLRow& rhs) { return (rhs < lhs); }

    /**
     * @brief
     * @param lhs
     * @param rhs
     * @return
     */
    inline bool operator<=(const XLRow& lhs, const XLRow& rhs) { return !(lhs > rhs); }

    /**
     * @brief
     * @param lhs
     * @param rhs
     * @return
     */
    inline bool operator>=(const XLRow& lhs, const XLRow& rhs) { return !(lhs < rhs); }

}    // namespace OpenXLSX

#ifdef _MSC_VER    // conditionally enable MSVC specific pragmas to avoid other compilers warning about unknown pragmas
#   pragma warning(pop)
#endif // _MSC_VER

#endif    // OPENXLSX_XLROW_HPP
