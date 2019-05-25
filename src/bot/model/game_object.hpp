/**
 * @file game_object.hpp
 *
 *  @author	bartlomiej
 *  @date	May 12, 2019
 *  @brief	Moduł klasy GameObject
 */

#ifndef BOT_MODEL_GAME_OBJECT_HPP_
#define BOT_MODEL_GAME_OBJECT_HPP_

#include <cmath>

namespace model {
//!  Klasa GameObject.
/*!
  Klasa obiektu gry w rozumieniu bota; po niej dziedziczą wszystkie obiekty stanu gry.
*/
class GameObject {
	//! Prywatna składowa; współrzędna x obiektu.
	int coord_x_;
	//! Prywatna składowa; współrzędna y obiektu.
	int coord_y_;

public:
    //! Publiczny konstruktor domyślny.
    /*!
      \param x współrzędna x.
      \param y współrzędna y.
    */
	GameObject( int x = 0, int y = 0 ) : coord_x_( x ), coord_y_( y ){};
    //! Publiczny konstruktor kopiujący.
    /*!
      \param object stała referencja na obiekt klasy GameObject
    */
	GameObject( const GameObject& object ) : coord_x_( object.get_x() ), coord_y_( object.get_y() ){}
	//! Setter ustawia współrzędne obiektu gry.
	void set_coordinates( int x, int y ){ coord_x_ = x; coord_y_ = y; };
	//! Getter zwraca współrzędną x.
	int get_x() const { return coord_x_; }
	//! Getter zwraca współrzędną y.
	int get_y() const { return coord_y_; }
	//! Funkcja obliczająca odległość pomiędzy obiektami; pierwiastek z sumy kwadratów
	int get_distance( const GameObject& destination ) const { return sqrt( pow( coord_x_ - destination.get_x(), 2 ) +
		pow( coord_y_ - destination.get_y(), 2 ) ); }
	//! Wirtualny destruktor
	virtual ~GameObject(){};

};


}//end namespace

#endif /* BOT_MODEL_GAME_OBJECT_HPP_ */
