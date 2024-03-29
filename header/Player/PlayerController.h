#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"
#include "../../header/Powerup/PowerupConfig.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"
#include <vector>
#include "../../Bullet.h"

namespace Player {
    class PlayerView;
}

namespace Player
{
    class PlayerController : public Collision::ICollider
    {
    private:
        float elapsed_shield_duration;
        float elapsed_rapid_fire_duration;
        float elapsed_tripple_laser_duration;

        float elapsed_fire_duration;
        float elapsed_freez_duration;

        sf::Clock bulletCooldownClock;
        float bulletCooldownDuration;
        float timeSinceLastBullet; // Add this member variable

        sf::Vector2f playerPosition;
        std::vector<Bullet*> bullets;

        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();

        bool processPowerupCollision(ICollider* other_collider);
        bool processEnemyCollision(ICollider* other_collider);
        void updateFreezDuration();
        void freezPlayer();
        void updatePowerupDuration();

        void disableShield();
        void disableRapidFire();
        void disableTrippleLaser();

        void saveHighScore();

    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void fireBullet();
        void render();
        void reset();


        const std::vector<Bullet*>& getBullets() const;

        void decreasePlayerLive();
        inline void increaseScore(int val) { PlayerModel::player_score += val; }
        inline void decreaseScore(int val) { PlayerModel::player_score -= val; }
        inline void increaseEnemiesKilled(int val) { PlayerModel::enemies_killed += val; }
        inline void increaseBulletsFired(int val) { PlayerModel::bullets_fired += val; }

        void enableShield();
        void enableRapidFire();
        void enableTrippleLaser();

        sf::Vector2f getPlayerPosition();
        PlayerState getPlayerState();

        const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}