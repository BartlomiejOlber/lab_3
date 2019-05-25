/**
 * @file brain.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy Brain
 */

#ifndef BOT_BRAIN_HPP_
#define BOT_BRAIN_HPP_


#include "model/game_state.hpp"
#include "model/action.hpp"

namespace brain {
//!  Klasa Brain.
/*!
  Właściwa klasa implementacji algorytmu podejmowania decyzji przez bota.
*/
class Brain {

	//! Prywatna składowa; stan gry, czyli wszystkie obiekty wygenerowane przez klasę Screen Capture.
	model::GameState game_state_;

public:
    //! Publiczny konstruktor z parametrem klasy GameState.
    /*!
      \param game_state stała referencja na obiekt klasy GameState; zbiór wszystkich obiektów rozgrywki.
    */
	explicit Brain( const model::GameState& game_state ) : game_state_( game_state ){}
	//! Funkcja zawierająca algorytm podejmowania decyzji przez bota
	void play_round( model::ActionScenario& action_scenario );
	//! Setter ustawia początkowy stan gry.
	void set_start_state( const model::GameState& game_state ){ game_state_ = game_state; }
	//! Getter zwraca przewidywany stan gry po zakończeniu rundy.
	const model::GameState& get_final_game_state() const { return game_state_; }

private:
	//! Statyczna stała; współczynnik strat w walce.
	static constexpr double CASUALTIES_FACTOR_ = 0.4;
	//! Statyczna stała; współczynnik minimalnych strat w walce.
	static constexpr double MINIMAL_CASUALTIES_FACTOR_ = 0.1;
	//! Statyczna stała; współczynnik minimalnej przewagi do podjęcia walki.
	static constexpr double MINIMAL_DOMINANCE_FACTOR_ = 1.1;
	//! Statyczna stała; współczynnik maksymalnych strat do podjęcia opłacalnej walki.
	static constexpr double MAXIMAL_CASUALTIES_FACTOR_ = 0.05;
	//! Statyczna stała; współczynnik minimalnej odległości bohatera przeciwnika od swojego zamku.
	static const int MINIMAL_ENEMY_DISTANCE_FACTOR_ = 2;

	//! Funkcja wykonuje algorytm podejmowania decyzji o ruchu bohatera
	void make_hero_actions_( model::ActionScenario& action_scenario );
	//! Funkcja wykonuje algorytm podejmowania decyzji o działaniach zamku
	void make_castle_actions_( model::ActionScenario& action_scenario );
	//! Funkcja zwraca logiczną wartość czy atak na oddział jest opłacalny
	bool is_attack_worth_( const model::Troop& troop );
	//! Funkcja zwraca logiczną wartość czy atak na zamek jest opłacalny
	bool is_attack_worth_( const model::Castle& enemy_castle );
	//! Funkcja zwraca logiczną wartość czy atak na bohatera jest opłacalny
	bool is_attack_worth_( const model::Hero& enemy_hero );
	//! Funkcja zwraca logiczną wartość czy atak na strzeżony budynek jest opłacalny
	bool is_attack_worth_( const model::GuardedBuilding& guarded_building );
	//! Funkcja zwraca logiczną wartość czy dla danej ilości punktów ruchu obiekt jest osiągalny
	bool is_reachable_( int movement_points, const model::GameObject& object );
	//! Funkcja oblicza liczbę strat w walce
	int count_battle_casualties_( int opponent_force );
	//! Funkcja oblicza ile jednostek jest możliwych do zakupienia
	int count_available_to_buy_( int gold, int cost, int limit );
	//! Funkcja znajduje najbliższy bohaterowi strzeżony budynek na mapie
	void find_closest_guarded_building_( model::GuardedBuilding& guarded_building );
	//! Funkcja znajduje najbliższy bohaterowi budynek na mapie
	void find_closest_building_( model::Building& building );
	//! Funkcja znajduje najbliższe bohaterowi złoto na mapie
	void find_closest_gold_( int& index, model::Gold& gold );
	//! Funkcja znajduje najbliższy bohaterowi oddział na mapie
	void find_closest_troop_( int& index, model::Troop& troop );
	//! Funkcja znajduje współrzędne miejsca na mapie, które jest najbliżej zamku przeciwnika uwzględniając liczbe punktów ruchu
	void find_enemy_castle_direction_( int movement_points, model::GameObject& direction );

};

}



#endif /* BOT_BRAIN_HPP_ */
