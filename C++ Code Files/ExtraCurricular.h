#pragma once // Header guard to prevent multiple inclusions
#include "CSpace.h"
#include <set>

class CPlayer;

class ExtraCurricular : public CSpace 
{
    private:
        const int mkMotivationalCost = 100; // Const Motivation cost for extracurricular activites
        const int mkSuccessScore = 20; // Const Success score for completion of extracurricular activities
        bool mCompleted = false; // Track completion status
        std::set<CPlayer*> mpCompletedPlayers; // Store players who complete an extra curricular activity

    public:
        /**
        * @brief Constructor for ExtraCurricular class
        *
        * @param[in] type The type of the space
        * @param[in] name The name of the space
        */
        ExtraCurricular( int type, const std::string& name );

        /**
        * @brief Method to check if an extracurricular activity is completed
        *
        * @return True if the extracurricular activity is completed, false otherwise
        */
        bool CheckCompleted() const;

        /**
        * @brief Method to mark an extra curricular activity as complete
        *
        * @param[in] player The player who completed the activity
        */
        void MarkCompleted( CPlayer* player );

        /**
        * @brief Method to get help for an extra curricular activity
        *
        * @param[in] currentPlayer The player requesting help
        */
        void HelpWithExtraCurricular( CPlayer* currentPlayer );

        /**
        * @brief Method to get completed players
        *
        * @return Constant reference to a set of pointers to CPlayer objects
        */
        const std::set<CPlayer*>& GetCompletedPlayers() const; // Returns constant refernce to a set of pointers to CPlayer objects

        /**
        * @brief Method to check if a player has completed the extra curricular activity
        *
        * @param[in] player The player to check
        * @return True if the player has completed the activity, false otherwise
        */
        bool CheckPlayerCompleted( const CPlayer* player ) const;

        /**
        * @brief Method to handle player landing on the space
        *
        * @param[in] player The player landing on the space
        */
        void LandOn( CPlayer& player ) override;
};
