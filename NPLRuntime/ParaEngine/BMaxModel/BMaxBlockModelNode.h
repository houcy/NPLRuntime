#pragma once
#include "BMaxNode.h"

namespace ParaEngine
{
	class Bone;

	/** block model node in bmax */
	struct BMaxBlockModelNode : public BMaxNode
	{
	public:
		BMaxBlockModelNode(BMaxParser* pParser, int16 x_, int16 y_, int16 z_, int32 template_id_, int32 block_data_);
		virtual ~BMaxBlockModelNode();
	public:
		const std::string& GetFilename() const;
		void SetFilename(const std::string& val);
		float GetFacing() const;
		void SetFacing(float val);
		
		virtual bool HasTransform();
		virtual Matrix4 GetTransform();
		void SetTransform(Matrix4& mat);

		virtual bool isSolid();

		virtual int TessellateBlock(BlockModel* tessellatedModel);
	public:
		std::string m_sFilename;
		float m_fFacing;
		Matrix4 matLocalTrans;
		bool bHasTransform;
	};
	typedef ref_ptr<BMaxBlockModelNode> BMaxBlockModelNodePtr;
}

