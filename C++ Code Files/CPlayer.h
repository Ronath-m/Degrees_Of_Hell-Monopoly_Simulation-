#pragma once // Header guard to prevent multiple inclusions
#include <string>
#include <vector>
#include <set>
#include "Assessment.h"
#include "ExtraCurricular.h"

class Degrees;

/**
 * @brief CPlayer class represents a player in the game
 */

class CPlayer 
{
    private:
        std::string mName = ""; // Store the name of the player
        int mMotivation = 0; // Store the motivation of the player
        unsigned int mSuccess = 0; // Store the success of the player
        int mPosition = 0; // Store the position on the board of the player
        int mYear = 0; // Store the year of the player
        bool mGameOver = false; // Store the bool of game over or not
        Degrees* mpDegreesPtr = nullptr; // Store a pointer to the Degrees object
        std::set<Assessment*> mpCompletedAssessments; // Set of pointers to completed assessments
        std::set<Assessment*> mpDefferredAssessments; // Set of pointers to defferred assessments
        std::set<ExtraCurricular*> mpCompletedExtraCurricular; // Set of pointers to completed extracurricular activities

        // Custom comparator for sorting assessments by motivational cost
        struct CompareByMotivationalCost 
        {
            bool operator()( const Assessment* a, const Assessment* b ) const 
        {
                return (a->GetMotivationalCost() < b->GetMotivationalCost());
            }
        };

    public:
        /**
        * @brief Constructor for CPlayer class
        *
        * @param[in] playerName The name of the player
        * @param[in] initialMotivation Initial motivation value for the player
        * @param[in] initialSuccess Initial success value for the player
        * @param[in] initialPosition Initial position value for the player
        * @param[in] initialYear Initial year value for the player
        */
        CPlayer( const std::string& playerName, int initialMotivation, int initialSuccess, int initialPosition, int initialYear );

        // Getter functions

        /**
        * @brief Get the player's name
        *
        * @return The player's name
        */
        std::string GetName() const;

        /**
        * @brief Get the player's motivation
        *
        * @return The player's motivation
        */
        int GetMotivation() const; 

        /**
        * @brief Get the player's success
        *
        * @return The player's success
        */
        int GetSuccess() const; 

        /**
        * @brief Get the player's position on the board
        *
        * @return The player's position
        */
        int GetPosition() const;

        /**
        * @brief Get the player's year
        *
        * @return The player's year
        */
        int GetYear() const; 

        /**
        * @brief Returns a reference to the set of completed assessments
        *
        * @return Reference to the set of completed assessments
        */
        std::set<Assessment*>& GetCompletedAssessments() ;

        /**
        * @brief Returns a reference to the set of deferred assessments
        *
        * @return Reference to the set of deferred assessments
        */
        std::set<Assessment*>& GetDefferredAssessments() ;

        // Setter functions

        /**
        * @brief Set the player's name
        *
        * @param[in] playerName The name to set
        */
        void SetName( const std::string& playerName );

        /**
        * @brief Set the player's motivation
        *
        * @param[in] newMotivation The motivation value to set
        */
        void SetMotivation( int newMotivation ); // Set players motivation

        /**
        * @brief Set the player's success
        *
        * @param[in] newSuccess The success value to set
        */
        void SetSuccess( int newSuccess ); // Set players success

        /**
         * @brief Set the player's position on the board
         *
         * @param[in] newPosition The position to set
         */
        void SetPosition( int newPosition ); // Set players position

          /**
         * @brief Set the player's year
         *
         * @param[in] newYear The year to set
         */
        void SetYear( int newYear ); // Set players year


        /**
         * @brief Method to increase player's motivation
         *
         * @param[in] amount The amount by which to increase the motivation
         */
        void IncreaseMotivation( int amount );

        /**
         * @brief Method to decrease player's motivation
         *
         * @param[in] amount The amount by which to decrease the motivation
         */
        void DecreaseMotivation( int amount );

        /**
          * @brief Method to increase player's success
          *
          * @param[in] amount The amount by which to increase the success
          */
        void IncreaseSuccess( int amount );

        /**
         * @brief Method to get a reference to the degrees object
         *
         * @param[in] degreesRef Pointer to the Degrees object
         */
        void GetDegreesReference( Degrees* degreesRef );

        /**
        * @brief Method to decrease player's success
        *
        * @param[in] amount The amount by which to decrease the success
        */
        void DecreaseSuccess( int amount );

        /**
        * @brief Method to increment player's year
        *
        * @param[in] increment The amount by which to increment the year
        */
        void IncrementYear( int increment );

        /**
        * @brief Method to check the graduation of the player
        *
        * @param[in] targetYear The target year for graduation
        * @return True if the player graduates in the target year, false otherwise
        */
        bool CheckGraduation( int targetYear );

        /**
        * @brief Method to sort completed assessments by motivational cost
        *
        * @return Vector of pointers to completed assessments sorted by motivational cost
        */
        std::vector<Assessment*> SortCompletedAssessmentsByMotivationCost();

        /**
        * @brief Method to handle mitigating circumstances / deferring assessments
        */
        void HandleMitigatingCircumstances();

        /**
        * @brief Method to move the player to a new position
        *
        * @param[in] newPos The new position to move the player to
        */
        void MovePlayer( int newPos );

        /**
        * @brief Method to check if the game is over
        *
        * @return True if the game is over, false otherwise
        */
        bool CheckGameOver();

        /**
        * @brief Method to handle deferred assessments / resubmissions
        */
        void HandleDeferredAssessments();

        /**
        * @brief Method to complete an assessment
        *
        * @param[in] motivationalCost The motivational cost of completing the assessment
        * @param[in] successScore The success score achieved upon completing the assessment
        * @param[in] assessmentPtr Pointer to the Assessment object
        */
        void CompleteAssessment( int motivationalCost, int successScore, Assessment* assessmentPtr );

        /**
        * @brief Method to complete an extra curricular activity
        *
        * @param[in] motivationalCost The motivational cost of completing the extra curricular activity
        * @param[in] successScore The success score achieved upon completing the extra curricular activity
        * @param[in] extraCurricularPtr Pointer to the ExtraCurricular object
        */
        void CompleteExtraCurricular( int motivationalCost, int successScore, ExtraCurricular* extraCurricularPtr );

        /**
        * @brief Method to handle passing of welcome week
        *
        * @param[in] previousPosition The previous position of the player
        * @param[in] welcomeWeekSpaceIndex The index of the welcome week space
        */
        void HandleMovementResult( int previousPosition, int welcomeWeekSpaceIndex );

        /**
        * @brief Method to ask for help with an assessment
        *
        * @param[in] halfMotivationalCost The half of the motivational cost of the assessment
        * @param[in] SuccessScore The success score required for help
        * @return Pointer to the player offering help
        */
        CPlayer* GetHelpAssessment( int halfMotivationalCost, int SuccessScore );

        /**
        * @brief Method to check if an assessment has been completed
        *
        * @param[in] assessmentName The name of the assessment to check
        * @return True if the assessment has been completed, false otherwise
        */
        bool CheckCompletedAssessment( const std::string& assessmentName );
};



