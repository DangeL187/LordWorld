class NPCUpdater {
protected:
    void updateNPCs(auto& time, auto& game) {
        for (auto& i: game.entity_manager->v_NPC) {
            i.update(time, game);
        }
    }
};
