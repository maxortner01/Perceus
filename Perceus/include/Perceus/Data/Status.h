#pragma once

#include "Inc.h"

namespace pcs
{
namespace Data
{
	/**
	 * @brief This is used to store and retreive various status codes 
	 * 		  and their corresponsing string values.
	 * @tparam E Enum class of status values. 
	 */
    template<class E>
    class Status
    {
        E status;

	protected:
		/**
		 * @brief Stores a static container of string values corresponding
		 *        to each of the enum values.
		 * @return std::vector<std::string>& Container of enum string names.
		 */
    	static std::vector<std::string> &getValues()
		{
			static std::vector<std::string> values;

			return values;
		}

		/// Set the current Status
        void setStatus(E s) { status = s; }

    public:
		/// Empty default constructor
		Status() {}
		/**
		 * @brief Initializes the class with a starting status.
		 * @param s The initial status of the class.
		 */
		Status(E s) :
			status(s)
		{
			
		}

		/**
		 * @brief Get the current status.
		 * @return E Current status of the class.
		 */
        E getStatus() const { return status; }

		/**
		 * @brief Get the string value of the current status.
		 * @return std::string String value of the current status.
		 */
		std::string getStatusValue() const
		{
			return getValues()[(int)getStatus()];
		}
		
		/**
		 * @brief Instance-free way of retreiving a string value of a given enum.
		 * 
		 * @param enumVal Enum value to get the corresponding string.
		 * @return std::string String value of a given enum.
		 */
        static std::string getStatusFromEnum(E enumVal) {
            return getValues()[(int)enumVal];
        }

		/**
		 * @brief Instance-free way of retreiving a string value of a given enum.
		 * 
		 * @param enumVal Integer value of an enum of type E.
		 * @return std::string String value of a given enum value.
		 */
		static std::string getStatusFromEnum(int enumVal) {
			return getStatusFromEnum((E)enumVal);
		}
    };
}
}
