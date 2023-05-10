// Copyright 2023 saito
#include <algorithm>
#include <array>
#include <cmath>
#include <exception>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>


class Robot {
    public:
        void do_action();
};

class Picrawler : public Robot {
    private:
        class MoveList;

        int A = 48;
        int B = 78;
        int C = 33;

        std::unique_ptr<MoveList> move_list;
        std::vector<std::pair<std::string, std::array<int, 3>>>
        move_list_add {"my action", {0}};

        float stand_position = 0.0f;
        std::array<int, 12> direction{0};
        std::array<std::array<int, 3>, 4> current_coord{0};
        std::array<std::array<int, 3>, 4> coord_temp{0};
        
        Picrawler();

    public:
        static Picrawler* get_instance();

        void coord2polar();
        void polar2coord();
        void limit();
        void limit_angle();
        void do_action(const std::string&, int, float);
        void set_angle();
        void do_step(int, int);
        void current_step_all_leg_angle();
        void add_action();
        void cali_helper_web();
        void do_single_let();
        void current_step_leg_value();
        void current_step_all_leg_value();
        void mix_step();

        Picrawler(const Picrawler&) = delete;
        Picrawler& operator=(const Picrawler&) = delete;
};

class Picrawler::MoveList  {
    public:
        float stand_position = 0.0f;

        std::array<std::array<std::array<int, 3>, 4>, 7>
        execute(const std::string&) {
            return forward();
        }

        void __getitem__();
        void turn_angle_coord();
        void check_stand();
        void normal_action();
        void sit();
        void stand();
        void ready();
        void is_sit();
        void is_stand();
    
    private:
        int LENGTH_SIDE = 77;
        int X_DEFAULT = 45;
        int X_TURN = 70;
        int X_START = 0;
        int Y_DEFAULT = 45;
        int Y_TURN = 130;
        int Y_WAVE =120;
        int Y_START = 0;
        int Z_DEFAULT = -50;
        int Z_UP = -30;
        int Z_WAVE = 60;
        int Z_TURN = -40;
        int Z_PUSH = -76;

        // temp length
        int TEMP_A = std::sqrt(pow(2 * X_DEFAULT + LENGTH_SIDE, 2) + pow(Y_DEFAULT, 2));
        int TEMP_B = 2 * (Y_START + Y_DEFAULT) + LENGTH_SIDE;
        int TEMP_C = std::sqrt(pow(2 * X_DEFAULT + LENGTH_SIDE, 2) + pow(2 * Y_START + Y_DEFAULT + LENGTH_SIDE, 2));
        int TEMP_ALPHA = std::acos((pow(TEMP_A, 2) + pow(TEMP_B, 2) - pow(TEMP_C, 2)) / 2 / TEMP_A / TEMP_B);
        // site for turn
        int TURN_X1 = (TEMP_A - LENGTH_SIDE) / 2;
        int TURN_Y1 = Y_START + Y_DEFAULT / 2;
        int TURN_X0 = TURN_X1 - TEMP_B * std::cos(TEMP_ALPHA);
        int TURN_Y0 = TEMP_B * std::sin(TEMP_ALPHA) - TURN_Y1 - LENGTH_SIDE;

        int z_current;


        std::array<std::array<std::array<int, 3>, 4>, 7>
        forward() {
            std::array<std::array<std::array<int, 3>, 4>, 7> ret_val;



            // [[self.X_DEFAULT, self.Y_DEFAULT, self.z_current]
            // [self.X_TURN, self.Y_START,self.Z_UP]
            // [self.X_DEFAULT, self.Y_START, self.z_current]
            // [self.X_DEFAULT, self.Y_DEFAULT, self.z_current]],
            ret_val[0][0] = {X_DEFAULT, Y_DEFAULT, z_current};
            ret_val[0][1] = {X_TURN, Y_START, Z_UP};
            ret_val[0][2] = {X_DEFAULT, Y_START, z_current};
            ret_val[0][3] = {X_DEFAULT, Y_DEFAULT, z_current};

            // [[self.X_DEFAULT, self.Y_DEFAULT, self.z_current]
            // [self.X_DEFAULT, self.Y_DEFAULT*2,self.Z_UP]
            // [self.X_DEFAULT, self.Y_START, self.z_current]
            // [self.X_DEFAULT, self.Y_DEFAULT, self.z_current]],
            ret_val[1][0] = {X_DEFAULT, Y_DEFAULT, z_current};
            ret_val[1][1] = {X_DEFAULT, Y_DEFAULT*2, Z_UP};
            ret_val[1][2] = {X_DEFAULT, Y_START, z_current};
            ret_val[1][3] = {X_DEFAULT, Y_DEFAULT, z_current};

            // [[self.X_DEFAULT, self.Y_DEFAULT, self.z_current]
            ret_val[2][0] = {X_DEFAULT, Y_DEFAULT, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT*2,self.z_current]
            ret_val[2][1] = {X_DEFAULT, Y_DEFAULT*2, z_current};
            // [self.X_DEFAULT, self.Y_START, self.z_current]
            ret_val[2][2] = {X_DEFAULT, Y_DEFAULT, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT, self.z_current]],
            ret_val[2][3] = {X_DEFAULT, Y_DEFAULT, z_current};

            // [[self.X_DEFAULT, self.Y_START, self.z_current]
            ret_val[3][0] = {X_DEFAULT, Y_START, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT,self.z_current]
            ret_val[3][1] = {X_DEFAULT, Y_DEFAULT, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT, self.z_current]
            ret_val[3][2] = {X_DEFAULT, Y_DEFAULT, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT*2, self.z_current]
            ret_val[3][3] = {X_DEFAULT, Y_DEFAULT*2, z_current};

            // [[self.X_DEFAULT, self.Y_START, self.z_current]
            ret_val[4][0] = {X_DEFAULT, Y_START, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT,self.z_current]
            ret_val[4][1] = {X_DEFAULT, Y_DEFAULT, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT, self.z_current]
            ret_val[4][2] = {X_DEFAULT, Y_DEFAULT, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT*2, self.Z_UP]]
            ret_val[4][3] = {X_DEFAULT, Y_DEFAULT*2, z_current};

            // [[self.X_DEFAULT, self.Y_START, self.z_current]
            ret_val[5][0] = {X_DEFAULT, Y_START, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT,self.z_current]
            ret_val[5][1] = {X_DEFAULT, Y_DEFAULT, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT, self.z_current]
            ret_val[5][2] = {X_DEFAULT, Y_DEFAULT, z_current};
            // [self.X_TURN, self.Y_START, self.Z_UP]]
            ret_val[5][3] = {X_TURN, Y_START, Z_UP};
            
            // [[self.X_DEFAULT, self.Y_START, self.z_current]
            ret_val[6][0] = {X_DEFAULT, Y_DEFAULT, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT,self.z_current]
            ret_val[6][1] = {X_DEFAULT, Y_DEFAULT, z_current};
            // [self.X_DEFAULT, self.Y_DEFAULT, self.z_current]
            ret_val[6][2] = {X_DEFAULT, Y_DEFAULT, z_current};
            // [self.X_DEFAULT, self.Y_START, self.z_current]
            ret_val[6][3] = {X_DEFAULT, Y_START, z_current};


            return ret_val;
        }
        
        void backward();
        void turn_left();
        void turn_right();
        void push_up();
        void wave();
        void look_left();
        void look_right();
        void turn_left_angle();
        void turn_right_angle();
        void look_up();
        void look_down();
        void rotate_body_absolute_x();
        void rotate_body_absolute_y();
        void move_body_absolute();
        void to_red();
        void dance();
};

void Picrawler::do_action(const std::string& motion_name, int step=1, float speed=50) {
    const std::array<std::string, 6> motions {
        "forward",
        "backward",
        "turn left",
        "turn right",
        "turn left angle",
        "turn right angle"
    };
    
    try {
        for (int i = 0; i < step; ++i) {
            move_list->stand_position = stand_position;

            if (std::find(motions.begin(), motions.end(), motion_name) != motions.end()) {
                stand_position = stand_position + 1;
            }
            auto actions = move_list->execute(motion_name);

            for (int _step = 0; _step < actions.size(); ++_step) {
                do_step(_step, speed);
            }
        }
    } catch (AttributeError e) {
        try {
            for (int i = 0; i < step; ++i) {
                auto action_add = move_list_add[motion_name];

                for (int _step = 0; _step < action_add.size(); ++_step) {
                    do_step(_step, speed);
                }
            }
        } catch (...) {
            std::cout << "No such action" << std::endl;
        }
    }
}