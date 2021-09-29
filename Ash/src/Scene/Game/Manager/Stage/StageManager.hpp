#pragma once

#include<Siv3D.hpp>

/*
	��) 2��ނ̍��W���ȉ��̕\���Ŏg��������.
	Vec2  pixel  -> �s�N�Z�����W : �����蔻���`��Ɏg�p
	Point square -> �}�X���W     : ��Q���̊Ǘ���o�H�T���Ɏg�p
*/

namespace Ash
{
	/// <summary>
	/// GameScene�ł̒n�`�ɂ��ĊǗ�
	/// </summary>
	class StageManager
	{
	private:

		// �n�`�̃}�X���W�ł̃T�C�Y
		Size m_size;

		// �n�` true�̂Ƃ���Q������
		Array<bool> m_terrain;

	public:

		/* ���W�ϊ� */

		/// <summary>
		/// 1�}�X�̈�ӂ̒���(�s�N�Z��)�̎擾
		/// </summary>
		/// <returns> 1�}�X�̈�ӂ̒���(�s�N�Z��) </returns>
		static double squareSize();

		/// <summary>
		/// �s�N�Z�����W����}�X���W�ɕϊ�
		/// </summary>
		/// <param name="pixel"> �s�N�Z�����W </param>
		/// <returns>
		/// �}�X���W
		/// </returns>
		Point pixelToSquare(const Vec2& pixel) const
		{
			return Floor((pixel / squareSize())).asPoint();
		}

		/// <summary>
		/// �}�X���W����s�N�Z�����W�ɕϊ�
		/// </summary>
		/// <param name="square"> �}�X���W </param>
		/// <returns>
		/// �}�X�̒��S�̃s�N�Z�����W
		/// </returns>
		Vec2 squareToPixel(const Point& square) const
		{
			return squareSize() * (Vec2::One() * square + Vec2::One() / 2.0);
		}

		/// <summary>
		/// �����l������ɑΉ�����}�X���W�ɕϊ�
		/// </summary>
		/// <param name="integer"> �����l </param>
		/// <returns>
		/// �}�X���W
		/// </returns>
		Point integerToSquare(int32 integer) const
		{
			return Point(integer % m_size.x, integer / m_size.x);
		}

		/// <summary>
		/// �}�X���W������ɑΉ����鐮���l�ɕϊ�
		/// </summary>
		/// <param name="square"> �}�X���W </param>
		/// <returns>
		/// �}�X���W�ɑΉ����鐮���l
		/// </returns>
		int32 squareToInteger(const Point& square) const
		{
			return square.x + m_size.x * square.y;
		}

		/// <summary>
		/// �s�N�Z�����W������ɑΉ����鐮���l�ɕϊ�
		/// </summary>
		/// <param name="pixel"> �s�N�Z�����W </param>
		/// <returns>
		/// �s�N�Z�����W�ɑΉ����鐮���l
		/// </returns>
		int32 pixelToInteger(const Vec2& pixel) const
		{
			return squareToInteger(pixelToSquare(pixel));
		}

		/// <summary>
		/// �����l������ɑΉ�����}�X�̒��S�s�N�Z�����W�ɕϊ�
		/// </summary>
		/// <param name="integer"> �����l </param>
		/// <returns>
		/// �����l�ɑΉ�����}�X�̒��S�s�N�Z�����W
		/// </returns>
		Vec2 integerToPixel(int32 integer) const
		{
			return squareToPixel(integerToSquare(integer));
		}

	public:

		/* LoadGameScene�Ŏg�p */

		/// <summary>
		/// ������
		/// </summary>
		/// <param name="size"> �n�`�̃}�X���W�ł̃T�C�Y </param>
		void init(const Size& size);

		/// <summary>
		/// �n�`��ݒ肷��
		/// </summary>
		/// <param name="square"> �}�X���W </param>
		/// <param name="wall"  > true�̂Ƃ���Q���̐ݒu, false�̂Ƃ���Q����r�� </param>
		void setTerrain(const Point& square, bool wall);

	public:

		/* GameScene�Ŏg�p */

		/// <summary>
		/// �w�肳�ꂽ�}�X���W���s���\��
		/// </summary>
		/// <param name="square"> �}�X���W </param>
		/// <returns> �X�e�[�W�O�ł���Ƃ����Q��������Ƃ� false , ����ȊO�̂Ƃ� true </returns>
		bool isWalkAble(const Point& square) const;

		/// <summary>
		/// �w�肳�ꂽ�s�N�Z�����W���s���\��
		/// </summary>
		/// <param name="pixel"> �s�N�Z�����W </param>
		/// <returns> �X�e�[�W�O�ł���Ƃ����Q��������Ƃ� false , ����ȊO�̂Ƃ� true </returns>
		bool isWalkAble(const Vec2& pixel) const
		{
			return isWalkAble(pixelToSquare(pixel));
		}

		/// <summary>
		/// �f�o�b�O�p�̒n�`�̕`��
		/// </summary>
		void drawDebugTerrain() const;

	};
}