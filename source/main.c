#include <3ds.h>
#include <citro2d.h>

#include "player.h"
#include "enemy.h"

#define SCREEN_W 400
#define SCREEN_H 240
#define GROUND_Y 200

int main(int argc, char* argv[])
{
    gfxInitDefault();

    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();

    C3D_RenderTarget* top =
        C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

    Player player;
    Player_Init(&player);

    Enemy enemy;
    Enemy_Init(
        &enemy,
        180.0f,
        GROUND_Y - 16.0f,
        150.0f,
        300.0f
    );

    while (aptMainLoop())
    {
        hidScanInput();

        u32 keysDown = hidKeysDown();
        u32 keysHeld = hidKeysHeld();

        if(keysDown & KEY_START)
            break;

        Player_Update(
            &player,
            keysDown,
            keysHeld
        );

        Enemy_Update(&enemy);

        if(Enemy_CheckCollision(
            &enemy,
            player.x,
            player.y,
            player.width,
            player.height))
        {
            player.x = 40;
            player.y = 100;

            if(player.lives > 0)
                player.lives--;
        }

        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

        C2D_TargetClear(
            top,
            C2D_Color32(120, 200, 255, 255)
        );

        C2D_SceneBegin(top);

        /* Chão */
        C2D_DrawRectSolid(
            0,
            GROUND_Y,
            0.5f,
            SCREEN_W,
            SCREEN_H - GROUND_Y,
            C2D_Color32(50, 180, 50, 255)
        );

        Player_Draw(&player);
        Enemy_Draw(&enemy);

        C3D_FrameEnd(0);
    }

    C2D_Fini();
    C3D_Fini();
    gfxExit();

    return 0;
}
