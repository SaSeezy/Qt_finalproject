USE [Test]
GO
/****** Object:  Table [dbo].[Manager]    Script Date: 01/06/2020 17:54:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Manager](
	[username] [varchar](20) NOT NULL,
	[password] [varchar](20) NOT NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Student]    Script Date: 01/06/2020 17:54:19 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Student](
	[dates] [varchar](20) NOT NULL,
	[degree] [varchar](15) NOT NULL,
	[studentID] [varchar](11) NOT NULL,
	[name] [varchar](20) NOT NULL,
	[roomNumber] [varchar](5) NOT NULL,
	[leavingTime] [varchar](6) NOT NULL,
	[reason] [varchar](20) NOT NULL,
	[returnTime] [varchar](6) NOT NULL,
	[taxi] [varchar](3) NOT NULL,
	[place] [varchar](15) NOT NULL,
	[temperature] [varchar](4) NOT NULL,
	[duration] [varchar](6) NOT NULL
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
