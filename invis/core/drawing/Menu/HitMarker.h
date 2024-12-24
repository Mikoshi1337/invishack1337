#include <deque>
namespace math {
	template <typename t>
	static t lerp(const t& t1, const t& t2, float progress)
	{
		return t1 + (t2 - t1) * progress;
	}
	template <typename t>
	static t lerp2(float t1, int t2, float progress)
	{
		return t1 + (t2 - t1) * progress;
	}
}
template <typename T>
class singleton
{
protected:
	singleton()
	{

	}
	~singleton()
	{

	}

	singleton(const singleton&) = delete;
	singleton& operator=(const singleton&) = delete;

	singleton(singleton&&) = delete;
	singleton& operator=(singleton&&) = delete;
public:
	static T& get()
	{
		static T inst
		{

		};

		return inst;
	}
};
struct hitmarker_t
{
	hitmarker_t(const float& time, const int& damage, const int& hitgroup, const Vector3& pos)
	{
		this->time = time;
		this->damage = damage;
		this->hitgroup = hitgroup;
		this->pos = pos;
		moved = 0.f;
		alpha = 255.f;
	}
	float time;
	int damage;
	int hitgroup;
	float moved;
	float alpha;
	Vector3 pos;
};

class hitmarker : public singleton<hitmarker>
{
public:
	void DrawDamageIndicator(ImDrawList* draw);
	void draw_hits(ImDrawList* draw);
	void render_damage(hitmarker_t& hit, const Vector2& screen_pos, Color col);
	void add_hit(hitmarker_t hit);
	static void render_hitmarker(hitmarker_t& hit, const Vector2& screen_pos, ImDrawList* draw);
	std::deque<hitmarker_t> hits;

	struct d_indicator_t {
		int damage;
		bool initialized;
		float erase_time;
		float last_update;
		BasePlayer* player;
		int hit_box;
		ImColor col;
		Vector3 position;
		Vector3 end_position;
	};

	std::vector<d_indicator_t> d_indicators;
private:

};

static int RandomInt(int iMin, int iMax)
{
	int num = iMin + rand() % (iMax - iMin + 1);
	return iMin + rand() % (iMax - iMin + 1);
}
void hitmarker::DrawDamageIndicator(ImDrawList* draw)
{
	float CurrentTime = Time::time();
	for (int i = 0; i < d_indicators.size(); i++) {

		if (d_indicators[i].erase_time < CurrentTime) {
			d_indicators.erase(d_indicators.begin() + i);
			continue;
		}

		if (d_indicators[i].erase_time - 1.f < CurrentTime) {
			d_indicators[i].col.Value.w = math::lerp(d_indicators[i].col.Value.w, 0.f, 0.1f);
		}

		if (!d_indicators[i].initialized) {
			d_indicators[i].position = d_indicators[i].player->BonePosition(head);

			d_indicators[i].end_position = d_indicators[i].position + Vector3(2, RandomInt(0, -14), 1);

			d_indicators[i].initialized = true;
		}

		if (d_indicators[i].initialized) {
			d_indicators[i].position.z = math::lerp(d_indicators[i].position.z, d_indicators[i].end_position.z, 9 / 1.5f * Time::deltaTime());
			d_indicators[i].position.x = math::lerp(d_indicators[i].position.x, d_indicators[i].end_position.x, 9 / 1.5f * Time::deltaTime());
			d_indicators[i].position.y = math::lerp(d_indicators[i].position.y, d_indicators[i].end_position.y, 9 / 1.5f * Time::deltaTime());

			d_indicators[i].last_update = CurrentTime;
		}
		if (d_indicators[i].damage != 0)
		{
			Vector2 ScreenPosition;
			std::string damage = "-";
			damage += std::to_string(d_indicators[i].damage);
			if (Camera::world_to_screen(d_indicators[i].position, ScreenPosition)) {
				g_Render->DrawString(ImVec2(ScreenPosition.x, ScreenPosition.y), ImColor(1.f, 1.0f, 1.0f), render2::outline, DefaultFonts, 12, damage.c_str());
			}
		}
	}
}
void hitmarker::draw_hits(ImDrawList* draw)
{
	if (funcs::localplayer::damagemarker)
		DrawDamageIndicator(draw);
	if (funcs::localplayer::hitmarker)
	{
		for (auto i = 0; i < hits.size(); i++)
		{
			auto& hit = hits[i];

			if (hit.time + 2.1f < Time::time())
			{
				hits.erase(hits.begin() + i);
				i--;
			}

			Vector2 screen_pos;

			if (Camera::world_to_screen(hit.pos, screen_pos))
			{
				render_hitmarker(hit, screen_pos, draw);
			}
		}
	}
}

void hitmarker::add_hit(const hitmarker_t hit)
{
	hits.push_back(hit);
}


void hitmarker::render_hitmarker(hitmarker_t& hit, const Vector2& screen_pos, ImDrawList* draw)
{
	static auto line_size = 6;

	const auto step = 255.f / 1.0f * Time::deltaTime();
	const auto step_move = 30.f / 1.5f * Time::deltaTime();
	const auto multiplicator = 0.3f;

	hit.moved -= step_move;

	if (hit.time + 1.8f <= Time::time())
		hit.alpha -= step;

	const auto int_alpha = static_cast<float>(hit.alpha);

	if (int_alpha > 0)
	{
		auto col = ImColor(255.f, 255.f, 255.f, int_alpha);
		const int size = 4;
		const int gap = 3;
		const float thickness = 1.f;
		const int padding = 2;
		const float expire_time = 0.75f;
		g_Render->DrawLine({ screen_pos.x - padding, screen_pos.y - padding }, ImVec2(screen_pos.x - padding - size, screen_pos.y - padding - size), ImColor(1.f, 1.0f, 1.0f, int_alpha), thickness);
		g_Render->DrawLine({ screen_pos.x + padding, screen_pos.y + padding }, ImVec2(screen_pos.x + padding + size, screen_pos.y + padding + size), ImColor(1.f, 1.0f, 1.0f, int_alpha), thickness);
		g_Render->DrawLine({ screen_pos.x + padding, screen_pos.y - padding }, ImVec2(screen_pos.x + padding + size, screen_pos.y - padding - size), ImColor(1.f, 1.0f, 1.0f, int_alpha), thickness);
		g_Render->DrawLine({ screen_pos.x - padding, screen_pos.y + padding }, ImVec2(screen_pos.x - padding - size, screen_pos.y + padding + size), ImColor(1.f, 1.0f, 1.0f, int_alpha), thickness);
	//g_Render->DrawLine({ entities::radar::pos.x+ size/2, entities::radar::pos.y +3}, ImVec2(entities::radar::pos.x + size / 2, entities::radar::pos.y + 3+size-6), ImColor(0, 0, 0, 255),1.2);
	}
}
