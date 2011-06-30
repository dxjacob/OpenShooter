#pragma once
#include <vector>
#import "vectormath/vectormath_aos.h"
using namespace Vectormath::Aos;


struct Projectile
{
    Point3 position;
    Vector3 direction;
    
    Projectile(Point3 position, Vector3 direction)
    : position(position), direction(direction)
    {}
};

class GameState
{
public:
    GameState();
    void Shoot();
    void RotatePlayer(float angle);
    void Update(float dt);
    const std::vector<Projectile>& GetProjectiles() { return projectiles_; }
    const std::vector<Point3>& GetEnemies() { return enemies_; }
    const Point3& GetPlayerPosition() { return playerPosition_; }
    float GetPlayerDirection() { return playerDirection_; }

private:
    std::vector<Projectile> projectiles_;
    std::vector<Point3> enemies_;
    Point3 playerPosition_;
    float totalTime_;
    float lastSpawnTime_;
    float playerDirection_;
    
    void HandleCollision();
    void SpawnEnemies();
    void UpdateEnemies(float dt);
    void UpdateProjectiles(float dt);
};