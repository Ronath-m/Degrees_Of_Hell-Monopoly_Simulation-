#pragma once // Header guard to prevent multiple inclusions
#include "CSpace.h"
#include <set>

class CPlayer;

/**
 * @brief Assessment class represents a space on the game board that serves as an assessment
 */
class Assessment : public CSpace 
{
    private:
        int mMotivationalCost = 0; // Cost of motivation required for an assessment
        int mSuccessScore = 0; // Score gained for a successful completion
        bool mCompleted = false; // Track completion status
        int mAssessmentYear = 0; // Assigned year for an assessment
        std::set<CPlayer*> mpCompletedPlayers; // Players who have completed the assessment

    public:

        /**
        * @brief Constructor for Assessment class
        *
        * @param[in] type The type of the space
        * @param[in] name The name of the assessment
        * @param[in] motivationalCost The motivational cost of completing the assessment
        * @param[in] successScore The success score achieved upon completing the assessment
        * @param[in] assessmentYear The year in which the assessment is due
        */
        Assessment( int type, const std::string& name, int motivationalCost, int successScore, int assessmentYear );

        // Getter functions

        /**
        * @brief Get the motivational cost of the assessment
        *
        * @return The motivational cost
        */
        int GetMotivationalCost() const; 
        /**
        * @brief Get the success score of the assessment
        *
        * @return The success score
        */
        int GetSuccessScore() const; 

        /**
        * @brief Get the assessment year of the assessment
        *
        * @return The assessment year
        */
        int GetYear() const; 

        /**
        * @brief Check if the assessment has been completed
        *
        * @return True if completed, false otherwise
        */
        bool CheckCompleted() const;

        /**
        * @brief Mark the assessment as completed by a player
        *
        * @param[in] player The player who completed the assessment
        */
        void MarkCompleted( CPlayer* player );

        /**
        * @brief Get help for the current player with the assessment
        *
        * @param[in] currentPlayer The player requesting help
        */
        void GetHelpWithAssessment( CPlayer* currentPlayer );

        /**
        * @brief Remove a player from the list of deferred assessment completed players
        *
        * @param[in] player The player to be removed
        */
        void RemoveDefferrdPlayer( CPlayer* player );

        /**
        * @brief Add a previously deferred player to the completed list after submission of deferred assessment
        *
        * @param[in] player The player to be added
        */
        void AddDefferrdPlayer( CPlayer* player );

        /**
        * @brief Get the set of completed players
        *
        * @return Set of completed players
        */
        const std::set<CPlayer*>& GetCompletedPlayers() const;

        void LandOn( CPlayer& player ) override;

        /**
        * @brief Check if a player has completed the assessment
        *
        * @param[in] player The player to check
        * @return True if the player has completed the assessment, false otherwise
        */
        bool CheckPlayerCompleted( const CPlayer* player ) const;
};


