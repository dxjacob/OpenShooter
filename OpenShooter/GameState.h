#pragma once
#include <vector>
#import "vectormath/vectormath_aos.h"
using namespace Vectormath::Aos;

class GameState
{
public:
    GameState();
    void Shoot();
    void Update(float dt);
    const std::vector<Point3>& GetProjectiles() { return projectiles_; }
    const std::vector<Point3>& GetEnemies() { return enemies_; }
    const Point3& GetPlayerPosition() { return playerPosition_; }

private:
    std::vector<Point3> projectiles_;
    std::vector<Point3> enemies_;
    Point3 playerPosition_;
    float totalTime_;
    float lastSpawnTime_;
    
    void HandleCollision();
    void SpawnEnemies();
    void UpdateEnemies(float dt);
    void UpdateProjectiles(float dt);
};