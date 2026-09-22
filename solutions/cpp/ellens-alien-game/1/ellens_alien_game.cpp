namespace targets
{
    class Alien
    {
        private:
            int health = 3;
        
        public:
            int x_coordinate = 0;
            int y_coordinate = 0;
            
            Alien()
            {
                
            }

            Alien(int new_x_coordinate, int new_y_coordinate)
            {
                x_coordinate = new_x_coordinate;
                y_coordinate = new_y_coordinate;
            }

            int get_health()
            {
                return health;
            }

            void set_health(int current_health)
            {
                health = current_health;
            }

            bool is_alive()
            {
                bool is_alive_bool = true;

                if(get_health() <= 0)
                {
                    is_alive_bool = false;
                }

                return is_alive_bool;
            }

            bool hit()
            {
                if(is_alive())
                {
                    set_health(get_health() - 1);
                }

                return true;
            }

            bool teleport(int new_x_coordinate, int new_y_coordinate)
            {
                x_coordinate = new_x_coordinate;
                y_coordinate = new_y_coordinate;

                return true;
            }

            bool collision_detection(Alien other_alien)
            {
                bool collision_detection_bool = false;

                if((x_coordinate == other_alien.x_coordinate) && (y_coordinate == other_alien.y_coordinate))
                {
                    collision_detection_bool = true;
                }

                return collision_detection_bool;
            }
    };
}  // namespace targets
